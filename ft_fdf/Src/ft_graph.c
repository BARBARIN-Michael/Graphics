/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:28:35 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/27 17:21:50 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

void		draw_pixel_to_img(int x, int y, t_mlx *mlx, color unitcolor)
{
	color r;
	color g;
	color b;

	r = ((unitcolor & 0xFF0000) >> 16);
	g = ((unitcolor & 0xFF0000)	>> 8);
	b = ((unitcolor & 0xFF0000));

	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8))    ] = b;
	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8)) + 1] = g;
	mlx->data[(y * mlx->sizeline + x * (mlx->bpp / 8)) + 2] = r;
}

void		draw_line(t_coord cl, t_mlx *mlx)
{
	int		x;
	int		dir;

	dir = direction_vector(cl.x1, cl.y1, cl.x2, cl.y2);
	if (dir > 2 && dir < 5)
		cl = rotate_direction(cl);
	x = cl.x1;
	while (x <= cl.x2)
	{
		draw_pixel_to_img(x, cl.y1 + ((cl.y2 - cl.y1) * (x - cl.x1))
				/ (cl.x2 - cl.x1), mlx, RED);
		x++;
	}
}

void		draw_fdf(t_mlx *mlx, t_list *lstfile, size_vector len_vector)
{
	t_coord		cnew;
	t_coord		cpre;
	int			lenx;
	t_axe		xyz;

	xyz.y = 0;
	while (lstfile != NULL)
	{
		xyz.x = 1;
		cpre = new_vector(0, 0, 0, coord_y_iso(xyz.y, xyz.x, 0));
		lenx = ft_coord_nbr(lstfile->content);
		while ((lenx - xyz.x) > 0)
		{

			xyz.z = ft_getvalue(lstfile->content, xyz.x);
			cnew = new_vector(cpre.x2, cpre.y2, coord_x_iso(xyz.x, xyz.y),
					coord_y_iso(xyz.x, xyz.y, xyz.z));
			ft_putendl_c(ft_itoa(cnew.x1), "green");
			ft_putendl_c(ft_itoa(cnew.x2), "green");
			cnew = trans_vectoriel(cnew, len_vector);
			ft_putendl_c(ft_itoa(cnew.x1), "cyan");
			ft_putendl_c(ft_itoa(cnew.y1), "cyan");
			ft_putendl_c(ft_itoa(cnew.x2), "magenta");
			ft_putendl_c(ft_itoa(cnew.y2), "magenta");
			//ft_putendl_c(ft_itoa(cnew.z), "blue");
			draw_line(cnew, mlx);
			xyz.x++;
		}
		lstfile = lstfile->next;
		xyz.y++;
	}
}
