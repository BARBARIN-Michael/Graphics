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
#include <math.h>

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
		cam->wall.x = (cam->coord_map.x + 1.0 - cam->raypos.x) * cam->wall_next.x;
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
		cam->wall.y = (cam->raypos.y - cam->coord_map.y) * cam->wall_next.y;
	}
	else if (mod == 1)
	{
		data->stape.y = 1;
		cam->wall.y = (cam->coord_map.y + 1.0 - cam->raypos.y) * cam->wall_next.y;
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
		if (cam->wall.x < cam->wall.y)
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
		if (env->world_map->line[cam->coord_map.x][cam->coord_map.y] > 0)
			data->collision = TRUE;
	}
}

static void	calc_sweep(t_move *data, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	if (data->wall_hor == FALSE)
		cam->lenght_wall = fabs((cam->coord_map.x - cam->raypos.x + (1 - data->stape.x) / 2) / cam->raydir.x);
	else
		cam->lenght_wall = fabs((cam->coord_map.y - cam->raypos.y + (1 - data->stape.y) / 2.0) / cam->raydir.y);
	cam->height_wall = abs((int)(env->wh.height / cam->lenght_wall));
}
 
void		ft_engine_rc(int x, t_env *env)
{
	t_move		data;
	t_datacam	*cam;
	t_datagame	*game;
	t_rgb		rgb;

	cam = env->datacam;
	game = env->datagame;
	data = (t_move) {	.stape = 0, .collision = FALSE, .wall_hor = FALSE};
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
	ft_draw_line_v(x, (t_line) {0, data.px.start}, env, (t_rgb){120, 120, 120});
	ft_draw_line_v(x, data.px, env, rgb);
	if (data.px.end < env->wh.height && data.px.end > 0)
		ft_draw_line_v(x, (t_line) {data.px.end, env->wh.height}, env, (t_rgb){0xAF, 0xFA, 0xAF});
	env->map == 1 ? ft_mapdesign(env), 0 : 1;
	ft_manage_move(env);
}
