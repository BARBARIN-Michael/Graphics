/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:13:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:01:01 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <math.h>

void	ft_movement_up(t_env *env)
{
	t_datagame	*game;
	int			move_speed;
	t_coord		world;

	game = env->datagame;
	move_speed = env->fps * 3;
	world.x = game->pos.x + game->dir.x * move_speed;
	if (env->world_map->line[world.x][(int)(game->pos.y)] == FALSE)
		game->pos.x += game->dir.x * move_speed;
	world.y = game->pos.y + game->dir.y * move_speed;
	if (env->world_map->line[(int)(game->pos.x)][world.y] == FALSE)
		game->pos.y += game->dir.y * move_speed;
}

void	ft_movement_down(t_env *env)
{
	t_datagame	*game;
	int			move_speed;
	t_coord		world;

	game = env->datagame;
	move_speed = env->fps * 5;
	world.x = game->pos.x - game->dir.x * move_speed;
	if (env->world_map->line[world.x][(int)(game->pos.y)] == FALSE)
		game->pos.x += game->dir.x * move_speed;
	world.y = game->pos.y - game->dir.y * move_speed;
	if (env->world_map->line[(int)(game->pos.x)][world.y] == FALSE)
		game->pos.y += game->dir.y * move_speed;
}

void	ft_movement_right(t_env *env)
{
	t_datagame	*game;
	int		old_dir_x;
	int		old_plan_x;
	int		rad_speed;

	rad_speed = env->fps * 3;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	game->dir.x = game->dir.x * cos(-rad_speed) - game->dir.y * sin(-rad_speed);
	game->dir.y = old_dir_x * sin(-rad_speed) + game->dir.y * cos(-rad_speed);
	game->plane.x = game->plane.x * cos(-rad_speed) - game->plane.y * sin(-rad_speed);
	game->dir.y = old_dir_x * sin(-rad_speed) + game->dir.y * cos(-rad_speed);
}

void	ft_movement_left	(t_env *env)
{
	t_datagame	*game;
	int		old_dir_x;
	int		old_plan_x;
	int		rad_speed;

	rad_speed = env->fps * 3;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	game->dir.x = game->dir.x * cos(rad_speed) - game->dir.y * sin(rad_speed);
	game->dir.y = old_dir_x * sin(rad_speed) + game->dir.y * cos(rad_speed);
	game->plane.x = game->plane.x * cos(rad_speed) - game->plane.y * sin(rad_speed);
	game->dir.y = old_dir_x * sin(rad_speed) + game->dir.y * cos(rad_speed);
}
