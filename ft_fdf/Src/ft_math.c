/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 12:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/04 17:17:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

/* ***********************************************************
** Controle the direction of this vector
** 4 value return :
** 1  : if the vector direction is right and positively
** 2  : if the vector direction is left and positively
** 3  : if the vector derection is vertical
** -1 : defaut, error, ...
 * *********************************************************** */
int		correct_vector(t_vector *vec1)
{
	if (vec1->x1 < vec1->x2 && vec1->y1 > vec1->y2)
		return (1);
	else if (vec1->x1 < vec1->x2 && vec1->y1 < vec1->y2)
	{
		vec1 = rotate_direction(vec1);
		return (2);
	}
	else if (vec1->x1 > vec1->x2 && vec1->y1 > vec1->y2)
		return (2);
	else if (vec1->x1 > vec1->x2 && vec1->y1 < vec1->y2)
	{
		vec1 = rotate_direction(vec1);
		return (1);
	}
	return (-1);
}

t_vector 		*rotate_direction(t_vector *cl)
{
	int		xtemp;
	int		ytemp;

	xtemp = cl->x2;
	cl->x2 = cl->x1;
	cl->x1 = xtemp;
	ytemp = cl->y2;
	cl->y2 = cl->y1;
	cl->y1 = ytemp;
	return (cl);
}

t_vector 		trans_vectoriel(t_vector vector, int tr_x, int tr_y)
{
		vector.x1 += abs(tr_x);
		vector.x2 += abs(tr_x);
		vector.y1 += abs(tr_y);
		vector.y2 += abs(tr_y);
	return (vector);
}

// A supprimer
t_vector 		new_vector(t_axe a, t_axe b)
{
	t_vector 		c1;

	c1 = (t_vector) { .x1 = a.x, .y1 = a.y, .x2 = b.x, .y2 = b.y };
	return (c1);
}

t_vector		new_vector_iso(t_axe a, t_axe b, int vec_w, int vec_h, int v_z)
{
	t_vector		iso;

	iso = (t_vector) {	.x1 = coord_x_iso(a.x, a.y, vec_w, vec_h),
						.y1 = coord_y_iso(a.x, a.y, a.z, vec_h, vec_w, v_z),
						.x2 = coord_x_iso(b.x, b.y, vec_w, vec_h),
						.y2 = coord_y_iso(b.x, b.y, b.z, vec_h, vec_w, v_z)};
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
