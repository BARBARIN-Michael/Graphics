/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 12:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/02 14:09:26 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>
#include <def.h>

/*
static t_complex init_complex(t_fract fract, t_coord x, t_coord y)
{
	t_complex	i;

	i = (t_complex) {	.c_r = x / (fract.zoom + fract.area.xy1.x),
						.c_i = y / (fract.zoom + fract.area.xy1.y),
						.z_r = 0, .z_i = 0};
	return (i);
}

static void calc_complex(t_fract fract, t_complex i, double x, double y, t_env *env)
{
	t_ushort tmp;
	t_ushort a;

	a = 0;
	while (1)
	{
		tmp = i.z_r;
		i.z_r = i.z_r * i.z_r - i.z_i * i.z_i + i.c_r;
		i.z_i = 2 * i.z_i * tmp + i.c_i;
		a++;
		//printf("test : %f et a : %d\n", (SQRT(i.z_r) + SQRT(i.z_i)), a);
		if (!((i.z_r * i.z_r + i.z_i * i.z_i) < 4 && a < fract.iterate))
			break;
	}
	if (a == fract.iterate)
	{
		//printf(C_BROWN"On rentre ici\n");
		ft_draw_pixel(xy.x, xy.y, ft_create_rgb("FF0000"), env);
	}
}
*/
void	ft_mandelbrot(t_fract fract, t_env *env)
{
	t_coord		img_xy;
	int			zoom = 100;
	int			iterate = 50;
	
	fract = fract;
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;

	ft_memset(env->mlx.data_tmp, '\0', env->mlx.sizeline * env->height);
	img_xy.x = (double)((x2 - x1) * (double)zoom);
	img_xy.y = (double)((y2 - y1) * (double)zoom);
	for (int x = 0; x < img_xy.x; x++)
	{
		for (int y = 0; y < img_xy.y; y++)
		{
			double c_r = x / (double)zoom + x1;
			double c_i = y / (double)zoom + y1;
			double z_r = 0;
			double z_i = 0;
			int a = 0;
			do {
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				a++;
			} while (z_r * z_r + z_i * z_i < 4 && a < iterate);
			if (a == iterate)
				ft_draw_pixel(x, y, ft_create_rgb("FF0000"), env);
		}
	}
}
