/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/31 18:03:22 by mbarbari         ###   ########.fr       */
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

void		draw_pixel_to_img(int x, int y, t_mlx *mlx, color unitcolor)
{
	color r;
	color g;
	color b;

	r = ((unitcolor & 0xFF0000) >> 16);
	g = ((unitcolor & 0xFF00)	>> 8);
	b = ((unitcolor & 0xFF));

	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8))    ] = b;
	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8)) + 1] = g;
	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8)) + 2] = r;

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

void		draw_fdf(t_mlx *mlx, t_node *map, size_vector len_vector)
{
	t_vector	v_left;
	t_vector	v_right;
	t_node		*c_node;

	c_node = map;
	while (c_node)
	{
		while (c_node)
		{
			if (c_node->left_node)
			{
				v_left = new_vector_iso(c_node->xyz, c_node->left_node->xyz, 40, 40);
				v_left = trans_vectoriel(v_left, 452, 452);
				create_line(v_left, mlx, RED);
			}
			if (c_node->right_node)
			{
				v_right = new_vector_iso(c_node->xyz, c_node->right_node->xyz, 40, 40);
				v_right = trans_vectoriel(v_right, 452, 452);
				create_line(v_right, mlx, RED);
			}
			if (c_node->left_node)
				ecrire_vecteur(v_left, c_node->xyz.x, c_node->left_node->xyz.z, GRE);
			if (c_node->right_node)
				ecrire_vecteur(v_right, 0, c_node->right_node->xyz.z, GRE);
				if (!c_node->left_node)
					break ;
				c_node = c_node->left_node;
		}
		c_node = c_node->first_xnode;
		c_node = c_node->right_node;
	}
}
