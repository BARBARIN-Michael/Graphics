/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/03 23:45:20 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

// A supprimer en fin de projet
void		ecrire_vecteur(t_vector cneww, int x, int z, color col)
{
			ft_putstr_c("Point Numero : ", "cyan");
			printf("%d "C_MAGENTA" color: %02X", x, col);
			fflush(stdout);
			ft_putstr_c(" Hauteur : ", "cyan");
			printf("%d", z);
			fflush(stdout);
			ft_putstr_c("           (x:", "green");
			printf("%d", cneww.x1);
			fflush(stdout);
			ft_putstr_c(", y:", "green");
			printf("%d", cneww.y1);
			fflush(stdout);
			ft_putstr_c(") ------- > (x:", "green");
			printf("%d", cneww.x2);
			fflush(stdout);
			ft_putstr_c(", y:", "green");
			printf("%d", cneww.y2);
			fflush(stdout);
			ft_putendl_c(")", "green");
}

static void	create_vector(t_env *env, t_node *c_node, bool left_right)
{
	t_vector	v_vec;

	if (left_right == 0)
		v_vec = new_vector_iso(c_node->xyz, c_node->left_node->xyz,
			env->dx, env->dy);
	else
		v_vec = new_vector_iso(c_node->xyz, c_node->right_node->xyz,
			env->dx, env->dy);
	v_vec = trans_vectoriel(v_vec, env->w, env->h);
	create_line(v_vec, &env->mlx, RED);
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

	x += env->w;
	y += env->h;

	tabi = ((y * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
	
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	env->mlx.data[tabi    ] = b;
	env->mlx.data[tabi + 1] = g;
	env->mlx.data[tabi + 2] = r;
}

void		create_line(t_vector v1, t_mlx *mlx, color col)
{
	int		dx;
	int		dy;
	int		direction_vector;

	dx = v1.x2 - v1.x1;
	dy = v1.y2 - v1.y1;
	draw_line1(v1, mlx, col);
}

void		draw_fdf(t_env *env)
{
	t_vector	v_left;
	t_vector	v_right;
	t_node		*c_node;

	c_node = env->map;
	while (c_node)
	{
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
