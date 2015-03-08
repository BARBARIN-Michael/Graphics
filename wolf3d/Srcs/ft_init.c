/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:56:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 18:32:25 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <libft.h>

void		first_init(t_env *env)
{
	env->datagame.pos = (t_coord) {.x = 200, .y = 200};
	env->datagame.dir = (t_dir) {.x = -1000, .y = 0};
	env->datagame.plane = (t_coord) {.x = 0, .y = 660};
	env->datagame.t = (t_time) {.time = 0, .oldtime = 0};
}

void		new_init(int x, t_env *env)
{
	t_datacam cam;
	t_datagame game;

	cam = &env->datacam;
	game = &env->datagame;
	cam = (t_datacam) 
	{
		.cam_x = 2 * x * 1000 / env->width - 1,
		.raypos.y = game.pos.y,
		.raypos.x = game.pos.x,
		.raydir.x = game.dir.x + game.plane.x * cam.cam_x,
		.raydir.y = game.dir.y + game.plane.y * cam.cam_x,
		.map.x = (int)(cam.raypos.x / 1000),
		.map.y = (int)(cam.raypos.x / 1000),
		.wall_next.x = SQRT(1 + SQRT(cam.raydir.y) / SQRT(cam.raydir.x)),
		.wall_next.x = SQRT(1 + SQRT(.raydir.x) / SQRT(cam.raydir.y))
	};
}
