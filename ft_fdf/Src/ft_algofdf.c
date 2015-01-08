/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 18:24:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/08 21:10:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

double		coord_x_iso(int x, int y, int tile_width, int tile_height)
{
	double rslt;
	
//	x *= tile_width;
//	y *= tile_height;
	rslt = (0.82 * x - 0.82 * y);
	return (ceil(rslt));
}

double		coord_y_iso(int x, int y, int z, int t_h, int t_w, int t_z)
{
	double rslt;

//	x *= t_w;
//	y *= t_h;
//	z *= t_z;
	rslt = (-z + (0.82 / 2.0 * x + 0.82 * y));
	return (ceil(rslt));
}
