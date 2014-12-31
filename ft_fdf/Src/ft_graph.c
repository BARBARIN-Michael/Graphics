/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/31 08:53:33 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

// A supprimer en fin de projet
void		ecrire_vecteur(t_vector cneww, double x, double z)
{
			ft_putstr_c("Point Numero : ", "cyan");
			printf("%f", x);
			fflush(stdout);
			ft_putstr_c(" Hauteur : ", "cyan");
			printf("%f", z);
			fflush(stdout);
			ft_putstr_c("           (x:", "green");
			printf("%f", cneww.x1);
			fflush(stdout);
			ft_putstr_c(", y:", "green");
			printf("%f", cneww.y1);
			fflush(stdout);
			ft_putstr_c(") ------- > (x:", "green");
			printf("%f", cneww.x2);
			fflush(stdout);
			ft_putstr_c(", y:", "green");
			printf("%f", cneww.y2);
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
}

void		draw_line(t_vector cl, t_mlx *mlx, color col)
{
	int		x;
	int		calculX;
	int		calculY;
	int		dir;

	dir = direction_vector(cl.x1, cl.y1, cl.x2, cl.y2);
/*	if (dir > 2 && dir < 5)
		cl = rotate_direction(cl);
*/	x = cl.x1;
	if ((cl.x2 - cl.x1) == 0)
	{
		ft_putendl_c("J'ai tout casse sur une formule math impossible", "red");
		return  ;
	}
	while (x <= cl.x2)
	{
		draw_pixel_to_img(ceil(x),
				ceil((cl.y1 + ((cl.y2 - cl.y1) * (x - cl.x1)) / (cl.x2 - cl.x1))),
				mlx, col);
	x++;
	}
}

void		draw_line2(t_vector v1, t_mlx *mlx, color col)
{
	
}

void		draw_fdf(t_mlx *mlx, t_node *map, size_vector len_vector)
{
	t_vector	v_left;
	t_vector	v_right;
	t_node		*c_node;
	t_axe		left;
	t_axe		right;

	c_node = map;
	while (c_node->right_node)
	{
		while (c_node)
		{
			if (c_node->left_node)
			{
				right = (t_axe) {	.x = c_node->xyz.x,
								.y = c_node->xyz.y,
								.z = c_node->xyz.z};
				v_left = new_vector_iso(c_node->xyz, c_node->left_node->xyz);
				trans_vectoriel(v_left, 10, 10);
				//draw_line(v_left, mlx, RED);
				ecrire_vecteur(v_left, right.x, right.z);
			}
				right = (t_axe) {	.x = 51,
								.y = 50,
								.z = 0};
				left = (t_axe) {	.x = 307,
								.y = 1,
								.z = 0};
			v_right = new_vector(right, left);
			//trans_vectoriel(v_right, 10, 10);
			draw_line(v_right, mlx, RED);
			ecrire_vecteur(v_right, right.x, right.z);
		//	if (!c_node->left_node)
				break ;
			c_node = c_node->left_node;
			sleep(1);
		}
		c_node = c_node->first_xnode;
		c_node = c_node->right_node;
	}
}
