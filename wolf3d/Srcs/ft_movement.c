/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:13:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/17 16:00:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <math.h>

void	ft_movement_up(t_env *env)
{
	t_coord new;
	double move_speed;

	if (env->framerate > 0)
		move_speed = 0.0001 + env->speed;
	else
		move_speed = env->framerate * 0.05;
	new.x = (int)(env->datagame->pos.x + env->datagame->dir.x * move_speed);
	new.y = (int)(env->datagame->pos.y + env->datagame->dir.y * move_speed);
	if(env->world_map->line[new.x][(int)(env->datagame->pos.y)] == FALSE)
		env->datagame->pos.x += env->datagame->dir.x * move_speed ;
	if(env->world_map->line[(int)(env->datagame->pos.x)][new.y] == FALSE)
		env->datagame->pos.y += env->datagame->dir.y * move_speed;
}

void	ft_movement_down(t_env *env)
{
	t_coord new;
	double move_speed;

	if (env->framerate > 0)
		move_speed = 0.0001 + env->speed;
	else
		move_speed = env->framerate * 0.05;
	new.x = (int)(env->datagame->pos.x - env->datagame->dir.x * move_speed);
	new.y = (int)(env->datagame->pos.y - env->datagame->dir.y * move_speed);
	if(env->world_map->line[new.x][(int)(env->datagame->pos.y)] == FALSE)
		env->datagame->pos.x -= env->datagame->dir.x * move_speed;
	if(env->world_map->line[(int)(env->datagame->pos.x)][new.y] == FALSE)
		env->datagame->pos.y -= env->datagame->dir.y * move_speed;
}

void	ft_movement_right(t_env *env)
{
	t_datagame	*game;
	double	old_dir_x;
	double	old_plan_x;
	double	rad_speed;
	double	sincos[2];

	if (env->framerate > 0)
		rad_speed = 0.00003;
	else
		rad_speed = env->framerate * 3.0;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	sincos[0] = sin(-rad_speed);
	sincos[1] = cos(-rad_speed);
	game->dir.x = game->dir.x * sincos[1] - game->dir.y * sincos[0];
	game->dir.y = old_dir_x * sincos[0] + game->dir.y * sincos[1];
	game->plane.x = game->plane.x * sincos[1] - game->plane.y * sincos[0];
	game->plane.y = old_plan_x * sincos[0] + game->plane.y * sincos[1];
}

void	ft_movement_left	(t_env *env)
{
	t_datagame	*game;
	double	old_dir_x;
	double	old_plan_x;
	double	rad_speed;
	double	sincos[2];

	if (env->framerate > 0)
		rad_speed = 0.00003;
	else
		rad_speed = env->framerate * 3.0;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	sincos[0] = sin(rad_speed);
	sincos[1] = cos(rad_speed);
	game->dir.x = game->dir.x * sincos[1] - game->dir.y * sincos[0];
	game->dir.y = old_dir_x * sincos[0] + game->dir.y * sincos[1];
	game->plane.x = game->plane.x * sincos[1] - game->plane.y * sincos[0];
	game->plane.y = old_plan_x * sincos[0] + game->plane.y * sincos[1];
}
