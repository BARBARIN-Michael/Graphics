/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 18:24:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/12 14:51:18 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

double		coord_x_iso(t_axe xy, int tile_width, int tile_height)
{
	double rslt;

	xy.x *= tile_width;
	xy.y *= tile_height;
	rslt = (0.82 * xy.x - 0.82 * xy.y);
	return (ceil(rslt));
}

double		coord_y_iso(t_axe xyz, int t_h, int t_w, int t_z)
{
	double rslt;

	xyz.x *= t_w;
	xyz.y *= t_h;
	xyz.z *= t_z;
	rslt = (-xyz.z + (0.82 / 2.0 * xyz.x + 0.82 * xyz.y));
	return (ceil(rslt));
}
