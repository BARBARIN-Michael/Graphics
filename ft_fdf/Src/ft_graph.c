/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/09 17:14:02 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

static void		create_vector(t_env *env, t_node *c_node, bool left_right)
{
	t_vector	v_vec;

	if (env->prof != 0)
		modifier_data_lst(&env->map, env->prof);
	env->prof = 0;
	if (left_right == 0)
	{
		v_vec = new_vector_iso(c_node->xyz, c_node->left_node->xyz,
			env->dx, env->dy, env->prof);
		v_vec = trans_vectoriel(v_vec, env->w, env->h);
		draw_line1(v_vec, env, c_node->col, c_node->left_node->col);
	}
	else
	{
		v_vec = new_vector_iso(c_node->xyz, c_node->right_node->xyz,
			env->dx, env->dy, env->prof);
		v_vec = trans_vectoriel(v_vec, env->w, env->h);
		draw_line1(v_vec, env, c_node->col, c_node->right_node->col);
	}
}

void		draw_pixel_to_img(int x, int y, color col, t_env *env)
{
	int		tabi;
	color	r;
	color	g;
	color	b;

	r = ((col & 0xFF0000) >> 16);
	g = ((col & 0xFF00)	>> 8);
	b = ((col & 0xFF));

	tabi = ((y * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	env->mlx.data[tabi    ] = b;
	env->mlx.data[tabi + 1] = g;
	env->mlx.data[tabi + 2] = r;
}

void		draw_fdf(t_env *env)
{
	t_node		*c_node;

	c_node = env->map;
	printf(C_MAGENTA"test de rentree de fonction : map.z2 = %d\n"C_NONE, env->map->xyz.z);
	while (c_node)
	{
	printf(C_CYAN"test de rentree de fonction : map.z\n"C_NONE);
		while (c_node)
		{
			if (c_node->left_node)
				create_vector(env, c_node, 0);
			if (c_node->right_node)
				create_vector(env, c_node, 1);
			if (!c_node->left_node)
				break ;
			c_node = c_node->left_node;
		}
		c_node = c_node->first_xnode;
		c_node = c_node->right_node;
	}
}
