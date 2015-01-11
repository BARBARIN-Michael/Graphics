/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 14:41:52 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/11 00:31:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

static void ft_move(int key, t_env *env)
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

static void ft_transform(int key, t_env *env)
{
	if (key == 65451)
	{
		env->dx += 5;
		env->dy += 5;
	}
	if (key == 65453)
	{
		env->dx -= 5;
		env->dy -= 5;
	}
}

static void ft_transform_prof(int key, t_env *env)
{
	if (key == 65457)
		env->prof += 1;
	if (key == 65459)
		env->prof -= 1;
}

static void ft_reset(int key, t_env *env)
{
	if (key == 65461)
	{
		env->dx = 40;
		env->dy = 40;
		env->prof = 3;
		env->w = WIDTH / 2 - 100;
		env->h = HEIGHT / 4;
	}
}

int		ft_event_key(int key, t_env *env)
{
	if (key == 65307)
		exit_fdf(env->map, &env->mlx);
	ft_move(key, env);
	ft_transform(key, env);
	ft_transform_prof(key, env);
	ft_reset(key, env);
	ft_icd_mlx(&env->mlx, 2, env->mlx.width, env->mlx.height);
	draw_fdf(env);
	ft_icd_mlx(&env->mlx, 1, env->mlx.width, env->mlx.height);
	return (0);
}

int		ft_event_expose(t_env *env)
{
	ft_icd_mlx(&env->mlx, 2, env->mlx.width, env->mlx.height);
	draw_fdf(env);
	ft_icd_mlx(&env->mlx, 1, env->mlx.width, env->mlx.height);
	return (0);
}
