/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 23:35:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:12:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <def.h>

static void	calc_movex(t_move *data, t_env *env, int mod)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
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

	cam = env->datacam;
	game = env->datagame;
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

	cam = env->datacam;
	game = env->datagame;
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
	printf(C_RED"valeur de x : line[0][0] = %d\n "C_GREEN"\n\n", env->world_map->line[0][0]);
		if (env->world_map->line[cam->coord_map.x][cam->coord_map.y] > 0)
			data->collision == TRUE;
	}
}

static void	calc_sweep(t_move *data, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	if (data->wall_hor == FALSE)
		cam->lenght_wall = ABS((cam->coord_map.x - cam->raypos.x
									+ (1 - data->stape.x) / 2) / cam->raydir.x);
	else
		cam->lenght_wall = ABS((cam->coord_map.y - cam->raypos.y
									+ (1 - data->stape.y) / 2) / cam->raydir.y);
	if (cam->lenght_wall != 0)
		cam->height_wall = ABS((int)env->wh.height / cam->lenght_wall);
}

void		ft_engine_rc(int x, t_env *env)
{
	t_move		data;
	t_datacam	*cam;
	t_datagame	*game;
	t_rgb		rgb;

	cam = env->datacam;
	game = env->datagame;
	printf(C_RED"valeur de x : cam->coord_map.x et y %d : cam->coord_map.y %d \n "C_GREEN"\n\n", cam->coord_map.x, cam->coord_map.x);
	data.collision = FALSE;
	printf(C_RED"premiere lecture : \n "C_GREEN"%s\n\n", env->mlx.data);
	cam->raydir.x < 0 ? calc_movex(&data, env, 0) : calc_movex(&data, env, 1);
	cam->raydir.y < 0 ? calc_movey(&data, env, 0) : calc_movey(&data, env, 1);
	calc_collision(&data, env);
	calc_sweep(&data, env);
	data.px.start = -cam->height_wall / 2 + env->wh.height / 2;
	data.px.start = data.px.start < 0 ? 0 : data.px.start;
	data.px.end = cam->height_wall / 2 + env->wh.height / 2;
	data.px.end = data.px.end >= env->wh.height ? env->wh.height - 1 : data.px.end;
	rgb = ft_get_color_by_pt(
			env->world_map->line[cam->coord_map.x][cam->coord_map.y],
			(data.wall_hor == TRUE ? 2 : 1));
	ft_draw_line_v(x, data.px, env, rgb);
}
