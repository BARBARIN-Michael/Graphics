/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:13:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/01 10:56:55 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <math.h>

static void	testing_secret(t_env *env, t_dir new)
{
	t_coord		xy;
	t_datagame	*g;
	int			t;

	g = env->datagame;
	if (((t = env->world_map->line[(int)new.x][(int)(g->pos.y)]) < 0))
	{
		xy = ft_parse_tp(env,
				(t_coord){(int)new.x, (int)(env->datagame->pos.y)}, t);
		xy.x != 0 && xy.y != 0 ? env->datagame->pos.y = (double)xy.x + 1, 0 : 1;
		xy.y != 0 && xy.y != 0 ? env->datagame->pos.x = (double)xy.y + 1, 0 : 1;
	}
	if (env->world_map->line[(int)(new.x)][(int)(env->datagame->pos.y)] == 8)
		env->datagame->pos.x += env->datagame->dir.x + 2;
	if (env->world_map->line[(int)(env->datagame->pos.x)][(int)(new.y)] == 8)
		env->datagame->pos.y += env->datagame->dir.y + 2;
	if (env->world_map->line[(int)(new.x)][(int)(env->datagame->pos.y)] == 7)
		env->datagame->pos.x += env->datagame->dir.x - 1;
	if (env->world_map->line[(int)(env->datagame->pos.x)][(int)(new.y)] == 7)
		env->datagame->pos.y += env->datagame->dir.y - 1;
}

void		ft_movement_up(t_env *env, t_move *data)
{
	t_dir	new;
	double	move_speed;

	move_speed = 0.00015 + env->speed;
	new.x = (env->datagame->pos.x + env->datagame->dir.x * move_speed);
	new.y = (env->datagame->pos.y + env->datagame->dir.y * move_speed);
	new.x += (data->wall_hor == 0 && data->stape.x == -1) ? -0.3 : 0.3;
	new.y += (data->wall_hor == 1 && data->stape.y == -1) ? -0.3 : 0.3;
	testing_secret(env, new);
	if (env->world_map->line[(int)new.x][(int)(env->datagame->pos.y)] <= FALSE)
		env->datagame->pos.x += env->datagame->dir.x * move_speed;
	if (env->world_map->line[(int)(env->datagame->pos.x)][(int)new.y] <= FALSE)
		env->datagame->pos.y += env->datagame->dir.y * move_speed;
}

void		ft_movement_down(t_env *env, t_move *data)
{
	t_dir	new;
	double	move_speed;

	move_speed = 0.00015 + env->speed;
	new.x = (env->datagame->pos.x - env->datagame->dir.x * move_speed);
	new.y = (env->datagame->pos.y - env->datagame->dir.y * move_speed);
	new.x += (data->wall_hor == 0 && data->stape.x == -1) ? -0.4 : 0.4;
	new.y += (data->wall_hor == 1 && data->stape.y == -1) ? -0.4 : 0.4;
	if (env->world_map->line[(int)new.x][(int)(env->datagame->pos.y)] <= FALSE)
		env->datagame->pos.x -= env->datagame->dir.x * move_speed;
	if (env->world_map->line[(int)(env->datagame->pos.x)][(int)new.y] <= FALSE)
		env->datagame->pos.y -= env->datagame->dir.y * move_speed;
}

void		ft_movement_right(t_env *env)
{
	t_datagame	*game;
	double		old_dir_x;
	double		old_plan_x;
	double		rad_speed;
	double		sincos[2];

	rad_speed = 0.00006;
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

void		ft_movement_left(t_env *env)
{
	t_datagame	*game;
	double		old_dir_x;
	double		old_plan_x;
	double		rad_speed;
	double		sincos[2];

	rad_speed = 0.00006;
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
