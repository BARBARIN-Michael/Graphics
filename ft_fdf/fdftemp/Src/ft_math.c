/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 12:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 03:54:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

t_vector		trans_vectoriel(t_vector vector, int tr_x, int tr_y)
{
	vector.x1 += tr_x;
	vector.x2 += tr_x;
	vector.y1 += tr_y;
	vector.y2 += tr_y;
	return (vector);
}

t_vector		new_vector_iso(t_axe a, t_axe b, t_env *env)
{
	t_vector	iso;
	int			vec_w;
	int			vec_h;
	double		vec_z;

	vec_w = env->dx;
	vec_h = env->dy;
	vec_z = env->prof;
	iso = (t_vector) {	.x1 = coord_x_iso(a, vec_w, vec_h),
						.y1 = coord_y_iso(a, vec_h, vec_w, vec_z),
						.x2 = coord_x_iso(b, vec_w, vec_h),
						.y2 = coord_y_iso(b, vec_h, vec_w, vec_z)};
	return (iso);
}

t_vector		new_vector_plane(t_axe a, t_axe b, t_env *env)
{
	t_vector	plane;
	int			vec_w;
	int			vec_h;

	vec_w = env->dx;
	vec_h = env->dy;
	plane = (t_vector) {.x1 = a.x * vec_w,
						.y1 = a.y * vec_h,
						.x2 = b.x * vec_w,
						.y2 = b.y * vec_h };
	return (plane);
}

t_vector		new_vector_par(t_axe a, t_axe b, t_env *env)
{
	t_vector	par;
	int			vec_w;
	int			vec_h;
	int			vec_z;

	vec_w = env->dx;
	vec_h = env->dy;
	vec_z = env->prof;
	par = (t_vector) {	.x1 = coord_x_par(a, vec_w, vec_h, vec_z),
						.y1 = coord_y_par(a, vec_h, vec_w, vec_z),
						.x2 = coord_x_par(b, vec_w, vec_h, vec_z),
						.y2 = coord_y_par(b, vec_h, vec_w, vec_z)};
	return (par);
}
