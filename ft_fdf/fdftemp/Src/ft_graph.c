/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 19:40:44 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

static void		create_vector(t_env *env, t_axe pt1, t_axe pt2, t_node *c_node)
{
	t_vector	v_vec;

	if (env->proj == 0)
		v_vec = new_vector_iso(pt1, pt2, env);
	else if (env->proj == 1)
		v_vec = new_vector_plane(pt1, pt2, env);
	else if (env->proj == 2)
		v_vec = new_vector_par(pt1, pt2, env);
	v_vec = trans_vectoriel(v_vec, env->w, env->h);
	v_vec.alt = pt2.z;
	draw_line1(v_vec, env, NULL, NULL);

}

void			draw_pixel_to_img(int x, int y, t_rgb col, t_env *env)
{
	int		tabi;

	if (x > (env->width - 1) || y > (env->height - 1) || x < 2 || y < 2)
		return ;
	tabi = ((y * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
	env->mlx.data[tabi] = col.b;
	env->mlx.data[tabi + 1] = col.g;
	env->mlx.data[tabi + 2] = col.r;
}

void			draw_fdf(t_env *e)
{
	t_node		*c_node;
	int			i;
	t_axe		xy[3];
	int			y;

	c_node = e->map;
	y = 0;
	while (c_node)
	{
		i = 0;
		while (i < c_node->elem)
		{
			xy[0] = (t_axe) {.x = i, .y = y, .z = c_node->tabz[i]};
			xy[1] = (t_axe) {.x = i + 1, .y = y, .z = c_node->tabz[i + 1]};
			if (c_node->next)
				xy[2] = (t_axe) {.x = i, .y = y + 1,
					.z = c_node->next->tabz[i]};
			create_vector(e, xy[0], xy[1], c_node);
			if (c_node->next && i <= c_node->next->elem)
				create_vector(e, xy[0], xy[2], c_node);
			i++;
		}
		y++;
		c_node = c_node->next;
	}
}
