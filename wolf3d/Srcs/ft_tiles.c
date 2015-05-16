/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:01:08 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:41:41 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <stdlib.h>

void			ft_orientation(t_move *data, t_env *env)
{
	t_datacam *cam;

	cam = env->datacam;
	data->texture.x = (int)(cam->wallx * (double)env->mlx.img[3].wh.width);
	if (data->wall_hor == FALSE && cam->raydir.x > 0)
		data->texture.x = env->mlx.img[3].wh.width - data->texture.x - 1;
	if (data->wall_hor == TRUE && cam->raydir.y < 0)
		data->texture.x = env->mlx.img[3].wh.width - data->texture.x - 1;
}

static t_dir	ft_floor(t_move *data, t_env *env)
{
	t_datacam	*cam;
	double		mod;
	t_dir		floor;

	cam = env->datacam;
	if (data->wall_hor == FALSE)
	{
		mod = cam->raydir.x < 0 ? 1.0 : 0.0;
		floor.x = cam->coord_map.x + mod;
		floor.y = cam->coord_map.y + cam->wallx;
	}
	else
	{
		mod = cam->raydir.y > 0 ? 0.0 : 1.0;
		floor.y = cam->coord_map.y + mod;
		floor.x = cam->coord_map.x + cam->wallx;
	}
	return (floor);
}

void			ft_draw_wall(t_move *data, t_env *env, int x)
{
	t_dir		fl;
	t_floor		calc;
	t_datacam	*cam;
	int			tabi[2];

	cam = env->datacam;
	calc = (t_floor) {.y = data->px.end, .x = x};
	calc.y = calc.y < 0 ? 0 : calc.y;
	fl = ft_floor(data, env);
	while (calc.y < env->wh.height)
	{
		calc.currentdist = env->wh.height / (2.0 * calc.y - env->wh.height);
		calc.weight = (calc.currentdist - 0) / (cam->lenght_wall - 0);
		calc.currentfloor.x = calc.weight * fl.x + (1.0 - calc.weight)
														* env->datagame->pos.x;
		calc.currentfloor.y = calc.weight * fl.y + (1.0 - calc.weight)
														* env->datagame->pos.y;
		calc.texture.x = (int)(calc.currentfloor.x * env->mlx.img[3].wh.width)
													% env->mlx.img[3].wh.width;
		calc.texture.y = (int)(calc.currentfloor.y * env->mlx.img[3].wh.height)
													% env->mlx.img[3].wh.height;
		if (!(calc.texture.y < 0) || !(calc.texture.x < 0))
			ft_color_floor(env, data, calc);
		calc.y++;
	}
}

void			ft_draw_collumn(t_move *data, t_env *env, int x)
{
	int			y;
	int			tabi;
	t_datacam	*cam;
	t_rgb		rgb;
	int			nt;

	cam = env->datacam;
	y = data->px.start;
	nt = env->world_map->line[cam->coord_map.x][cam->coord_map.y];
	while (y < data->px.end)
	{
		data->texture.y = (y * 2 - env->wh.height + cam->height_wall)
						* (env->mlx.img[nt].wh.height / 2) / cam->height_wall;
		if (data->texture.y < 0 || data->texture.x < 0)
		{
			y++;
			continue ;
		}
		tabi = ((y * env->mlx.img[0].sizeline) + (x * 4));
		ft_color_tile(env, data, tabi);
		y++;
	}
}
