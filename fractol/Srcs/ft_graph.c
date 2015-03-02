/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/02 19:20:41 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void			ft_draw_pixel(int x, int y, t_rgb col, t_env *env)
{
	int		tabi;

	if (x > (env->width - 1) || y > (env->height - 1) || x < 0 || y < 0)
		return ;
	tabi = ((y * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
	env->mlx.data_tmp[tabi] = col.b;
	env->mlx.data_tmp[tabi + 1] = col.g;
	env->mlx.data_tmp[tabi + 2] = col.r;
}
