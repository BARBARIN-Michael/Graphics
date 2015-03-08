/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:32:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 19:37:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_wolf.h>

static void	calc_movex(t_move *data, t_env *env, int mod)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = &env->datacam;
	game = &env->datagame;
	if (mod == 0)
	{
		data->stape.x = -1;
		cam->wall.x = (cam->raypos.x - cam->coord_map.x) * cam->wall_next.x;
	}
	else if (mod == 1)
	{
		data->stape.x = 1;
		cam->wall.x = (cam->coord_map.x + 1 - cam->raypos.x) * cam->wall_next.x;
	}
}

static void	calc_movey(t_move *data, t_env *env, int mod)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = &env->datacam;
	game = &env->datagame;
	if (mod == 0)
	{
		data->stape.y = -1;
		cam->wall.x = (cam->raypos.y - cam->coord_map.y) * cam->wall_next.x;
	}
	else if (mod == 1)
	{
		data->stape.y = 1;
		cam->wall.x = (cam->coord_map.y + 1 - cam->raypos.y) * cam->wall_next.x;
	}
}

static void calc_collision(t_move *data, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = &env->datacam;
	game = &env->datagame;
	while (data->collision == FALSE)
	{
		if (cam->wall.x < cam->wall_next.x)
		{
			cam->wall.x += cam->wall_next.x;
			cam->coord_map.x += data->stape.x;
			data->wall_hor = FALSE;
		}
		else
		{
			cam->wall.y += cam->wall_next.y;
			cam->coord_map.y += data->stape.y;
			data->wall_hor = TRUE;
		}
	}
	if (env->world_map[cam->coord_map.x][cam->coord_map.y] > 0)
		data->collision == TRUE;
}

static void	calc_sweep(t_move *data, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;
	t_rgb		px_rgb;

	cam = &env->datacam;
	game = &env->datagame;
	if (data->wall_hor == FALSE)
		cam->lenght_wall = ABS((cam->coord_map.x - cam->raypos.x
									+ (1 - data->stape.x) / 2) / cam->raydir.x);
	else
		cam->lenght_wall = ABS((cam->coord_map.y - cam->raypos.y
									+ (1 - data->stape.y) / 2) / cam->raydir.y);
	if (cam->lenght_wall != 0)
		cam->height_wall = ABS((int)env->height / cam->lenght_wall);
}

void		ft_new_calc_movement(t_env *env)
{
	t_move		data;
	t_datacam	*cam;
	t_datagame	*game;

	cam = &env->datacam;
	game = &env->datagame;
	data.collision = FALSE;
	cam->raydir.x < 0 ? calc_movex(&data, env, 0) : calc_movex(&data, env, 1);
	cam->raydir.y < 0 ? calc_movey(&data, env, 0) : calc_movey(&data, env, 1);
	calc_collision(&data, env);
	calc_sweep(&data, env);
	data.px.start = -cam->height_wall / 2 + env->height / 2;
	data.px.start = cam->draw_px_start < 0 ? 0 : cam->draw_px_start;
	data.px.end = cam->height_wall / 2 + env->height / 2;
	data.px.end = cam->draw_px_end >= h ? h - 1 : cam->draw_px_end;
	ft_get_color_by_pt(world_map[cam->coord_map.x][cam->coord_map.y], &rgb,
						data->wall_hor == TRUE ? 2 : 1);
	ft_draw_line_v(x, data.px, env, rgb);
}
