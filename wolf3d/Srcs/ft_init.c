/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:56:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:00:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <libft.h>
#include <def.h>
#include <math.h>

void		first_init(t_env *env)
{
	env->datagame->pos = (t_dir) {.x = 4.5, .y = 4.5};
	env->datagame->dir = (t_dir) {.x = -1.0, .y = 0.0};
	env->datagame->plane = (t_dir) {.x = 0.0, .y = 0.66};
	env->datagame->time = (t_time) {.time = 0.0, .oldtime = 0.0};
	env->fps = 0;
}

void		init_player_position(int x, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	cam->cam_x = 2 * x  / (double)(env->wh.width) - 1;
	cam->raypos.x = game->pos.x;
	cam->raypos.y = game->pos.y;
	cam->raydir.x = game->dir.x + game->plane.x * cam->cam_x;
	cam->raydir.y = game->dir.y + game->plane.y * cam->cam_x;
	cam->coord_map.x = (int)(cam->raypos.x);
	cam->coord_map.y = (int)(cam->raypos.y);
	cam->wall_next.x = sqrt(1 + (cam->raydir.y * cam->raydir.y) /
							(cam->raydir.x * cam->raydir.x));
	cam->wall_next.y = sqrt(1 + (cam->raydir.x * cam->raydir.x) /
							(cam->raydir.y * cam->raydir.y));
}
