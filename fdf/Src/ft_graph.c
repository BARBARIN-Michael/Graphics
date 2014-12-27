/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/24 03:18:57 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "stdio.h"

void		draw_pixel_to_img(int x, int y, t_mlx *mlx, color unitcolor)
{
	color r;
	color g;
	color b;
	int i = 0;

	t++;
	p++;
	r = ((unitcolor & 0xFF0000) >> 16);
	g = ((unitcolor & 0xFF00)	>> 8);
	b = ((unitcolor & 0xFF));

	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8))    ] = r;
	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8)) + 1] = g;
	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8)) + 2] = b;
}

void		draw_line(t_coord cl, t_mlx *mlx)
{
	int		x;
	int		xtemp;
	int		ytemp;
	int		dir;

	dir = direction_vector(cl.x1, cl.y1, cl.x2, cl.y2);
	if (dir > 2 && dir < 5)
		cl = rotate_direction(cl);
	x = cl.x1;
	while (x <= cl.x2)
	{
		draw_pixel_to_img(x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), mlx, RED);
		x++;
	}
}

void		draw_fdf(t_mlx *mlx, t_list *lstfile, size_vector len_vector)
{
	t_coord		cnew;
	t_coord		cpre;
	int		y;
	int		x;
	int		lenx;

	y = 0;
	while (lstfile != NULL)
	{
		cpre = new_vector(0, 0, 0, coord_y_iso(y));
		lenx = ft_coord_nbr(lstfile->content);
		x = 0;
		while ((lenx - x) > 0)
		{
			cnew = new_vector(cpre.x2, cpre.y2, coord_x_iso(x), coord_y_iso(y));
			cnew = trans_vectoriel(cnew, len_vector);
			draw_line(cnew, &mlx);
			x++;
		}
		lstfile = lstfile->next;
		y++;
	}
}
