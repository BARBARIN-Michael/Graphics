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
	t_coord new;
	double move_speed;

	move_speed = 0.1;
	new.x = (int)(env->datagame->pos.x + env->datagame->dir.x * move_speed);
	new.y = (int)(env->datagame->pos.y + env->datagame->dir.y * move_speed);
	if(env->world_map->line[new.x][(int)(env->datagame->pos.y)] == FALSE)
		env->datagame->pos.x += env->datagame->dir.x * move_speed ;
	if(env->world_map->line[(int)(env->datagame->pos.x)][new.y] == FALSE)
		env->datagame->pos.y += env->datagame->dir.y * move_speed;
	env->movement.up = FALSE;
}

void	ft_movement_down(t_env *env)
{
	t_coord new;
	double move_speed;

	move_speed = 0.1;
	new.x = (int)(env->datagame->pos.x - env->datagame->dir.x * move_speed);
	new.y = (int)(env->datagame->pos.y - env->datagame->dir.y * move_speed);
	if(env->world_map->line[new.x][(int)(env->datagame->pos.y)] == FALSE)
		env->datagame->pos.x -= env->datagame->dir.x * move_speed;
	if(env->world_map->line[(int)(env->datagame->pos.x)][new.y] == FALSE)
		env->datagame->pos.y -= env->datagame->dir.y * move_speed;
	env->movement.down = FALSE;
}

void	ft_movement_right(t_env *env)
{
	t_datagame	*game;
	double	old_dir_x;
	double	old_plan_x;
	double	rad_speed;

	//ft_bzero(env->mlx.data, env->mlx.sizeline * env->wh.height);
	rad_speed = env->framerate * 3.0;
	rad_speed = 0.03;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	game->dir.x = game->dir.x * cos(-rad_speed) - game->dir.y * sin(-rad_speed);
	game->dir.y = old_dir_x * sin(-rad_speed) + game->dir.y * cos(-rad_speed);
	game->plane.x = game->plane.x * cos(-rad_speed) - game->plane.y * sin(-rad_speed);
	game->plane.y = old_plan_x * sin(-rad_speed) + game->plane.y * cos(-rad_speed);
	env->movement.right = FALSE;
}

void	ft_movement_left	(t_env *env)
{
	t_datagame	*game;
	double	old_dir_x;
	double	old_plan_x;
	double	rad_speed;

	//ft_bzero(env->mlx.data, env->mlx.sizeline * env->wh.height);
	rad_speed = env->framerate * 3.0;
	rad_speed = 0.03;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	game->dir.x = game->dir.x * cos(rad_speed) - game->dir.y * sin(rad_speed);
	game->dir.y = old_dir_x * sin(rad_speed) + game->dir.y * cos(rad_speed);
	game->plane.x = game->plane.x * cos(rad_speed) - game->plane.y * sin(rad_speed);
	game->plane.y = old_plan_x * sin(rad_speed) + game->plane.y * cos(rad_speed);
	env->movement.left = FALSE;
}
