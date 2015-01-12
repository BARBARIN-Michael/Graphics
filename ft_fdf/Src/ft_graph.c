/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/12 19:05:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

static void		create_vector(t_env *env, t_node *c_node, t_bool left_right)
{
	t_vector	v_vec;

	if (left_right == 0)
	{
		if (env->proj == 0)
			v_vec = new_vector_iso(c_node->xyz, c_node->left_node->xyz, env);
		else if (env->proj == 1)
			v_vec = new_vector_plane(c_node->xyz, c_node->left_node->xyz, env);
		v_vec = trans_vectoriel(v_vec, env->w, env->h);
		v_vec.alt = c_node->left_node->xyz.z;
		draw_line1(v_vec, env, c_node->col, c_node->left_node->col);
	}
	else
	{
		if (env->proj == 0)
			v_vec = new_vector_iso(c_node->xyz, c_node->right_node->xyz,
				env);
		else if (env->proj == 1)
			v_vec = new_vector_plane(c_node->xyz, c_node->right_node->xyz, env);
		v_vec.alt = c_node->right_node->xyz.z;
		v_vec = trans_vectoriel(v_vec, env->w, env->h);
		draw_line1(v_vec, env, c_node->col, c_node->right_node->col);
	}
}

void			draw_pixel_to_img(int x, int y, t_rgb col, t_env *env)
{
	int		tabi;

	tabi = ((y * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
	if (x > (env->width - 1) || y > (env->height - 1) || x < 2 || y < 2)
		return ;
	env->mlx.data[tabi] = col.b;
	env->mlx.data[tabi + 1] = col.g;
	env->mlx.data[tabi + 2] = col.r;
}

void			draw_fdf(t_env *env)
{
	t_node		*c_node;

	c_node = env->map;
	while (c_node)
	{
		while (c_node)
		{
			if (c_node->left_node)
				create_vector(env, c_node, FALSE);
			if (c_node->right_node)
				create_vector(env, c_node, TRUE);
			if (!c_node->left_node)
				break ;
			c_node = c_node->left_node;
		}
		c_node = c_node->first_xnode;
		c_node = c_node->right_node;
	}
}
