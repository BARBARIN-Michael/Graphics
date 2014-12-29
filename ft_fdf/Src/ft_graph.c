/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/29 17:57:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

// A supprimer en fin de projet
void		ecrire_vecteur(t_coord cneww, double x, double z)
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

void		draw_line(t_coord cl, t_mlx *mlx, color col)
{
	int		x;
	int		dir;

	dir = direction_vector(cl.x1, cl.y1, cl.x2, cl.y2);
	if (dir > 2 && dir < 5)
		cl = rotate_direction(cl);
	x = cl.x1;
	if ((cl.x2 - cl.x1) == 0)
	{
		ft_putendl_c("J'ai tout casse sur une formule math impossible", "red");
		return  ;
	}
	while (x <= cl.x2)
	{
		draw_pixel_to_img(ceil(OFFSET_W - x),
				ceil(OFFSET_H - (cl.y1 + ((cl.y2 - cl.y1) * (x - cl.x1)) / (cl.x2 - cl.x1))),
				mlx, col);
	x++;
	}
}

void		draw_fdf(t_mlx *mlx, t_list *lstfile, size_vector len_vector)
{
	t_coord		cnew;
	t_coord		cpre;
	int			lenx;
	t_axe		xyz;
	int			cmp;

	xyz.y = 0.0;
	xyz.x = 0.0;
	while (lstfile != NULL)
	{
		cmp = 1;
		lenx = ft_coord_nbr(lstfile->content);
		cpre = new_vector(0.0, 0.0, coord_x_iso(xyz.x, xyz.y), coord_y_iso(xyz.x, xyz.y, 0));
		cpre = trans_vectoriel(cpre, OFFSET_XY);
		while (cmp <= lenx)
		{
			xyz.z = ft_getvalue(lstfile->content, cmp - 1);
			cnew = new_vector(cpre.x2, cpre.y2, coord_x_iso((xyz.x + (double)cmp) * OFFSET_XY, xyz.y * OFFSET_XY),
					coord_y_iso((xyz.x + (double)cmp) * OFFSET_XY, xyz.y * OFFSET_XY, xyz.z));
		//	cnew = trans_vectoriel(cnew, OFFSET_XY);
			ecrire_vecteur(cnew, cmp, xyz.z);
				draw_line(cnew, mlx, RED);
			cpre = cpy_vector(cpre, cnew);
			cmp++;
		}
		ft_putendl_c("###################################################################", "magenta");
		lstfile = lstfile->next;
		xyz.y++;
		xyz.x++;
	}
}

