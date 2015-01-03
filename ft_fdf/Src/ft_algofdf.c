/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 18:24:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/03 00:48:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

double		coord_x_iso(int x, int y, int tile_width, int tile_height)
{
	double rslt;
	
	x *= tile_width;
	y *= tile_height;
	rslt = (0.80 * x - 0.70 * y);
	return (ceil(rslt));
}

double		coord_y_iso(int x, int y, int z, int tile_height, int tile_width)
{
	double rslt;

	x *= tile_width;
	y *= tile_height;
	z *= 2;
	rslt = (0.70 * z) - (1 / sqrt(6)) * (x + y);
	rslt = (-z + (0.80/2 * x + 0.70 * y));
	return (ceil(rslt));
}

int			x_max(t_node *map)
{
	t_node	*sv;
	int		lenx;
	int		rslt;

	lenx = 0;
	sv = map;
	while (sv->left_node)
	{
		sv = sv->left_node;
		lenx++;
	}
	return (lenx);
}

int			y_max(t_node *map)
{
	t_node	*sv;
	int		leny[2];
	int		y;
	int offsety;
	int		rslt;

	//leny[0] = Hauteur positive
	//leny[1] = Hauteur negative
	sv = map;
	y = 0;
	leny[0] = 0;
	leny[1] = 0;
	while (sv->right_node)
	{
		while (sv->left_node)
		{
			if (leny[0] < (sv->xyz.z - y))
				leny[0] = sv->xyz.z - y;
			if (leny[1] > sv->xyz.z)
			{
				leny[1] = sv->xyz.z;
				offsety = 0;
			}
			else
				leny[1] += ++offsety;
			sv = sv->left_node;
		}
		y++;
	}
	return (leny[0] - leny[1]);
}
