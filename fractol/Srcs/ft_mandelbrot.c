/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 12:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 16:37:54 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>
#include <def.h>


static t_complex init_complex(t_fract fract, t_coord xy)
{
	t_complex	i;

	i = (t_complex) {	.c_r = xy.x / (fract.zoom + fract.area.xy1.x),
						.c_i = xy.y / (fract.zoom + fract.area.xy1.y),
						.z_r = 0, .z_i = 0};
	return (i);
}

static void calc_complex(t_fract fract, t_complex complex, t_coord xy, t_env *env)
{
	t_ushort tmp;
	t_ushort a;

	a = 0;
	while ((SQRT(i.z_r) + SQRT(i.z_i)) < 4 && a < frac.iterate)
	{
		tmp = i.z_r;
		i.z_r = (SQRT(i.z_r) - SQRT(i.z_i) + i.c_r);
		i.z_i = 2 * i.z_i * tmp + i.c_i;
		a++;
	}
	if (a == fract.iterate)
		ft_draw_pixel(xy.x, xy.y, ft_create_rgb("0000FF"), env);
}

void	ft_mandelbrot(const t_fract fract, t_env *env)
{
	t_coord		img_xy;
	t_coord		xy;
	t_complex	i;

	xy = (t_coord) {.x = 0, .y = 0};
	img_xy.x = (fract.area.xy2.x - fract.area.xy1.x) * fract.zoom;
	img_xy.y = (fract.area.xy2.y - fract.area.xy1.y) * fract.zoom;
	while (xy.x < img_xy.x)
	{
		while (xy.y < img_xy.y)
		{
			i = init_complex(fract, xy);
			calc_complex(fract, i, xy, env);
			xy.y++;
		}
		xy.x++;
	}
}
