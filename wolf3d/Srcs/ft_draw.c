/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                      :+:      :+:    :+:   	  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:32:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 19:37:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

void	ft_draw_line_v(int x, t_line line, t_env *env, t_rgb rgb)
{
	int tabi;

	while (line.start <= line.end)
	{
		tabi = ((line.start * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
		env->mlx.data[tabi] = rgb.b;
		env->mlx.data[tabi + 1] = rgb.g;
		env->mlx.data[tabi + 2] = rgb.r;
		line.start++;
	}
}
