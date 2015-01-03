/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/03 04:13:55 by mbarbari         ###   ########.fr       */
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

static void	create_vector(t_env *env, t_node *c_node)
{
	t_vector	v_vec;

	v_vec = new_vector_iso(c_node->xyz, c_node->right_node->xyz,
		env->dx, env->dy);
	v_vec = trans_vectoriel(v_vec, env->w, env->h);
	create_line(v_vec, env->mlx, RED);
}

void		draw_pixel_to_img(int x, int y, t_mlx *mlx, color unitcolor)
{
	int		tabi;
	color	r;
	color	g;
	color	b;

	r = ((unitcolor & 0xFF0000) >> 16);
	g = ((unitcolor & 0xFF00)	>> 8);
	b = ((unitcolor & 0xFF));

	x += HEIGHT / 2;
	y += WIDTH / 2;
	tabi = ((y * mlx->sizeline) + (x * (mlx->bpp / 8)));
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	mlx->data[tabi    ] = b;
	mlx->data[tabi + 1] = g;
	mlx->data[tabi + 2] = r;

	//printf(C_CYAN"On dessine le Point "C_RED"{x:"C_NONE"%d"C_RED" , y:"C_NONE"%d"C_RED"}\n"C_NONE, x, y);
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
				create_vector(env, c_node);
			if (c_node->right_node)
				create_vector(env, c_node);
			c_node = c_node->left_node;
		}
		c_node = c_node->first_xnode;
		c_node = c_node->right_node;
	}
}
