/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                      :+:      :+:    :+:   	  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:32:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/17 13:02:40 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static void ft_draw(int x, int y, t_env *env, t_rgb rgb)
{
	int		tabi;

	tabi = ((y * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
	env->mlx.data[tabi] = rgb.b;
	env->mlx.data[tabi + 1] = rgb.g;
	env->mlx.data[tabi + 2] = rgb.r;
}

void	ft_draw_line_v(int x, t_line line, t_env *env, t_rgb rgb)
{
	while (line.start <= line.end)
	{
		ft_draw(x, line.start, env, rgb);
		line.start++;
	}
}

void	ft_draw_line_map(int x, t_line line, t_env *env, t_rgb rgb)
{
	int		tabi;

	while (line.start <= line.end)
	{
		tabi = ((line.start * env->mlx.sizemap) + (x * (env->mlx.bpp / 8)));
		env->mlx.data_map[tabi] = rgb.b;
		env->mlx.data_map[tabi + 1] = rgb.g;
		env->mlx.data_map[tabi + 2] = rgb.r;
		line.start++;
	}
}

void	ft_draw_map(int x, int y, t_env *env, t_rgb rgb)
{
	int		nb_px;
	int		cmp;
	int		cmp2;
	int		tabi;

	nb_px = env->nb_px;
	x *= nb_px;
	y *= nb_px;
	cmp = 0;
	while (cmp <= nb_px)
	{
		cmp2 = y;
		while (cmp2 <= y + nb_px)
		{
			tabi = ((cmp2 * env->mlx.sizemap)
					+ ((x + cmp) * (env->mlx.bpp / 8)));
			env->mlx.data_map[tabi] = rgb.b;
			env->mlx.data_map[tabi + 1] = rgb.g;
			env->mlx.data_map[tabi + 2] = rgb.r;
			cmp2++;
		}
		cmp++;
	}
}
