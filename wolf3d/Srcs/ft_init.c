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

void		first_init(t_env *env)
{
	env->datagame->pos = (t_dir) {.x = 2, .y = 2};
	env->datagame->dir = (t_dir) {.x = -1, .y = 0};
	env->datagame->plane = (t_dir) {.x = 0, .y = 0.66};
	env->datagame->time = (t_time) {.time = 0, .oldtime = 0};
}

void		init_player_position(int x, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	*cam = (t_datacam)
	{
		.cam_x = 2 * x  / (double)(env->wh.width) - 1,
		.raypos.y = game->pos.y,
		.raypos.x = game->pos.x,
		.raydir.x = game->dir.x + game->plane.x * cam->cam_x,
		.raydir.y = game->dir.y + game->plane.y * cam->cam_x,
		.coord_map.x = (int)(cam->raypos.x),
		.coord_map.y = (int)(cam->raypos.x),
		.wall_next.x = SQRT(1 + SQRT(cam->raydir.y) / SQRT(cam->raydir.x)),
		.wall_next.y = SQRT(1 + SQRT(cam->raydir.x) / SQRT(cam->raydir.y))
	};
}
