/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 12:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/27 17:11:18 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

/* ***********************************************************
** Controle the direction of this vector
** 4 value return :
** 1 : if the vector direction is right and positively
** 2 : if the vector direction is right and negatively
** 3 : if the vector direction is left and positively
** 4 : if the vector direction is left and negatively
** 5 : if the vector derection is vertical
** 6 : if the vector derection is horizontal
 * *********************************************************** */
int		direction_vector(int x1, int y1, int x2, int y2)
{
	if (x1 < x2 && y2 > y1)
		return (1);
	else if (x1 < x2 && y2 < y1)
		return (2);
	else if (x1 > x2 && y1 < y2)
		return (3);
	else if (x1 > x2 && y1 > y2)
		return (4);
	else if (x1 == x2)
		return (5);
	else if (y1 == y2)
		return (5);
	return (-1);
}

t_coord		rotate_direction(t_coord cl)
{
	int		xtemp;
	int		ytemp;

	xtemp = cl.x2;
	cl.x2 = cl.x1;
	cl.x1 = xtemp;
	ytemp = cl.y2;
	cl.y2 = cl.y1;
	cl.y1 = ytemp;
	return (cl);
}

t_coord		trans_vectoriel(t_coord vector, int trans)
{
	if (vector.x2 > 0)
		vector.x2 += trans;
	if (vector.y2 > 0)
		vector.y2 += trans;
	return (vector);
}

t_coord		new_vector(int x1, int y1, int x2, int y2)
{
	t_coord		c1;

	c1 = (t_coord) { .x1 = x1, .y1 = y1, .x2 = x2, .y2 = y2 };
	return (c1);
}
