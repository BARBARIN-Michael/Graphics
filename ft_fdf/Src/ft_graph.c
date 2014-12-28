/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/28 19:07:41 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

// A supprimer en fin de projet
static void		ecrire_vecteur(t_coord cneww, int x, int z)
{
			ft_putstr_c("Point Numero : ", "cyan");
			ft_putstr_c(ft_itoa(x), "cyan");
			ft_putstr_c(" Hauteur : ", "cyan");
			ft_putstr_c(ft_itoa(z), "cyan");
			ft_putstr_c("           (x:", "green");
			ft_putstr_c(ft_itoa(cneww.x1), "red");
			ft_putstr_c(", y:", "green");
			ft_putstr_c(ft_itoa(cneww.y1), "red");
			ft_putstr_c(") ------- > (x:", "green");
			ft_putstr_c(ft_itoa(cneww.x2), "red");
			ft_putstr_c(", y:", "green");
			ft_putstr_c(ft_itoa(cneww.y2), "red");
			ft_putendl_c(")", "green");
			ft_putendl("###################################################################");
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
		ft_putendl_c("merde j'ai tout casse", "red");
		return  ;
	}
	while (x <= cl.x2)
	{
		draw_pixel_to_img(x - (WIDTH - 360),
				(HEIGHT) - (cl.y1 + ((cl.y2 - cl.y1) * (x - cl.x1)) / (cl.x2 - cl.x1)),
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

	xyz.y = 0;
	xyz.x = 0;
	while (lstfile != NULL)
	{
		cmp = 1;
		cpre = new_vector(0, 0, 0, xyz.y);
		lenx = ft_coord_nbr(lstfile->content);
		while (cmp <= lenx)
		{
			xyz.z = ft_getvalue(lstfile->content, cmp - 1);
			cnew = new_vector(cpre.x2, cpre.y2, coord_x_iso(xyz.x + cmp, xyz.y),
					coord_y_iso(xyz.x + cmp, xyz.y, xyz.z));
			//cnew = trans_vectoriel(cnew, OFFSET_XY);
			ecrire_vecteur(cnew, cmp, xyz.z);
			//ecrire_vecteur(cnew, xyz.x, xyz.z);
			draw_pixel_to_img(cnew.x2, cnew.y2, mlx, GRE);
			draw_pixel_to_img(cnew.x1, cnew.y1, mlx, RED);
	/*		if (xyz.x == 0)
				draw_line(cnew, mlx, GRE);
			else if (xyz.x >= -1)
				draw_line(cnew, mlx, BLU);
	*/		/*else
				draw_line(cnew, mlx, RED);
			*/cpre = cpy_vector(cpre, cnew);
			cmp++;
		}
		ft_putendl_c("###################################################################", "magenta");
		lstfile = lstfile->next;
		xyz.y++;
		xyz.x--;
	}
}

