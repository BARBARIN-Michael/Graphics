/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 18:24:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 00:36:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

int			coord_x_iso(t_axe xy, int tile_width, int tile_height)
{
	double rslt;

	xy.x *= tile_width;
	xy.y *= tile_height;
	rslt = (0.92 * xy.x - 0.82 * xy.y);
	printf("X : %d\n", rslt);
	return (ceil(rslt));
}

int			coord_y_iso(t_axe xyz, int t_h, int t_w, int t_z)
{
	double rslt;
	double z;

	z = xyz.z;
	xyz.x *= t_w;
	xyz.y *= t_h;
	z *= t_z;
	z *= 0.15;
	rslt = (-z + (0.92 / 2.0 * xyz.x + 0.82 * xyz.y));
	printf("Y : %d\n", rslt);
	return (ceil(rslt));
}

double		coord_x_par(t_axe xyz, int t_h, int t_w, int t_z)
{
	double rslt;
	double z;

	z = xyz.z;
	xyz.x *= t_w;
	xyz.y *= t_h;
	z *= t_z;
	z *= 0.05;
	rslt = (xyz.x + (-z * 0.82));
	return (ceil(rslt));
}

double		coord_y_par(t_axe xyz, int t_h, int t_w, int t_z)
{
	double rslt;
	double z;

	z = xyz.z;
	xyz.x *= t_w;
	xyz.y *= t_h;
	z *= t_z;
	z *= 0.05;
	rslt = (xyz.y + (0.82 / 2.0) * -z);
	return (ceil(rslt));
}
