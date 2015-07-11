/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:41:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 14:41:31 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static void	ft_draw(int x, int y, t_env *env, t_rgb rgb)
{
	int		tabi;
	char	*data;

	if (env->map == 1 && x < ((env->map_max.x - 1) * env->nb_px)
			&& y < ((env->map_max.y + 1) * env->nb_px))
		return ;
	data = env->mlx.img[0].data;
	tabi = ((y * env->mlx.img[0].sizeline) + (x * 4));
	data[tabi + 0] = rgb.b;
	data[tabi + 1] = rgb.g;
	data[tabi + 2] = rgb.r;
}

void		ft_draw_line_v(int x, t_line line, t_env *env, t_rgb rgb)
{
	while (line.start <= line.end)
	{
		ft_draw(x, line.start, env, rgb);
		line.start++;
	}
}

void		ft_draw_map(int x, int y, t_env *env, t_rgb rgb)
{
	int		nb_px;
	int		cmp[2];
	int		tabi;
	char	*data;

	nb_px = env->nb_px;
	x *= nb_px;
	y *= nb_px;
	cmp[0] = 0;
	data = env->mlx.img[0].data;
	while (cmp[0] <= nb_px)
	{
		cmp[1] = y;
		while (cmp[1] <= y + nb_px)
		{
			tabi = ((cmp[1]++ * env->mlx.img[0].sizeline) + ((x + cmp[0]) * 4));
			data[tabi] = rgb.b;
			data[tabi + 1] = rgb.g;
			data[tabi + 2] = rgb.r;
		}
		cmp[0]++;
	}
}
