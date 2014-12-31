/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 12:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/31 08:29:03 by mbarbari         ###   ########.fr       */
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

t_vector 		rotate_direction(t_vector cl)
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

t_vector 		trans_vectoriel(t_vector vector, int tr_x, int tr_y)
{
		vector.x1 *= tr_x;
		vector.x2 *= tr_x;
		vector.y1 *= tr_y;
		vector.y2 *= tr_y;
	return (vector);
}

t_vector 		new_vector(t_axe a, t_axe b)
{
	t_vector 		c1;

	c1 = (t_vector ) { .x1 = a.x, .y1 = a.y, .x2 = b.x, .y2 = a.y };
	return (c1);
}

t_vector		new_vector_iso(t_axe a, t_axe b)
{
	t_vector		iso;

	iso = (t_vector) {	.x1 = coord_x_iso(a.x, a.y),
						.y1 = coord_y_iso(a.x, a.y, a.z),
						.x2 = coord_x_iso(b.x, b.y),
						.y2 = coord_y_iso(b.x, b.y, b.z)};
	return (iso);
}

t_vector 		cpy_vector(t_vector v_out,t_vector v_in)
{
	v_out.x1 = v_in.x1;
	v_out.y1 = v_in.y1;
	v_out.x2 = v_in.x2;
	v_out.y2 = v_in.y2;
	return (v_out);
}
