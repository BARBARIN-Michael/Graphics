/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 14:41:52 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 02:24:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

static void	ft_move(int key, t_env *env)
{
	if (key == 65464)
		env->h -= 50;
	if (key == 65458)
		env->h += 50;
	if (key == 65460)
		env->w -= 50;
	if (key == 65462)
		env->w += 50;
}

static void	ft_reset(int key, t_env *env)
{
	t_axe		xy;

	if (key == 65461)
	{
		env->dx = 40;
		env->dy = 40;
		env->prof = 3;
		env->w = WIDTH / 2 - 100;
		env->h = HEIGHT / 4;
	}
	if (key == 114)
	{
		xy.x = (lenght_x_map(&env->map) * env->dx) / 2;
		xy.y = (lenght_y_map(&env->map) * env->dy) / 2;
		xy.z = 1;
		env->w = (env->width / 2) - coord_x_iso(xy, 1, 1);
		env->h = (env->height / 2) - coord_y_iso(xy, 1, 1, 1);
	}
}

static void	ft_transform(int key, t_env *env)
{
	if (key == 65451)
	{
		env->dx += 1;
		env->dy += 1;
	}
	if (key == 65453)
	{
		env->dx -= 1;
		env->dy -= 1;
	}
	if (key == 112)
	{
		if (env->proj == 1)
			env->proj = 2;
		else if (env->proj == 0)
			env->proj = 1;
		else if (env->proj == 2)
			env->proj = 0;
	}
	if (key == 65457)
		env->prof += 1;
	if (key == 65459)
		env->prof -= 1;
}

int			ft_event_key(int key, t_env *env)
{
	if (key == 65307)
		exit_fdf(env->map, &env->mlx);
	ft_transform(key, env);
	ft_move(key, env);
	ft_reset(key, env);
	ft_icd_mlx(env, 2);
	draw_fdf(env);
	ft_icd_mlx(env, 1);
	return (0);
}

int			ft_event_expose(t_env *env)
{
	ft_reset(114, env);
	ft_icd_mlx(env, 2);
	draw_fdf(env);
	ft_icd_mlx(env, 1);
	return (0);
}
