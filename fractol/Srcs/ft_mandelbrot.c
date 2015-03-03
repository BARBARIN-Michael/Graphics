/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 12:13:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/03 18:22:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>
#include <def.h>

void ft_zoom_mandelbrot(int x, int y, t_env *env)
{
	t_coord		xy;

	//recuperation du x et y sur l'ensemble de coordonne de la fractal
	xy.x = (x * ABS(env->fract.area.xy1.x) + ABS(env->fract.area.xy2.x))
			/ env->width;
	xy.x -= env->fract.area.xy2.x;
	xy.y = (y * ABS(env->fract.area.xy1.y) + ABS(env->fract.area.xy2.y))
			/ env->height;
	xy.y -= env->fract.area.xy2.y;
	env->fract.area.xy1.x -= xy.x * 0.001;
	env->fract.area.xy2.x += xy.x * 0.001;
	env->fract.area.xy1.y -= xy.y * 0.001;
	env->fract.area.xy2.y += xy.y * 0.001;
	env->fract.zoom *= 1.01;
	env->fract.iterate *= 1.0005;
	ft_mandelbrot(env->fract, env);
}

void ft_move_mandelbrot(int key, t_env *env)
{
	if (key == ARROW_UP)
	{
		if (env->fract.area.xy1.y >= -1.20001 && env->fract.area.xy1.y <= 0)
			env->fract.area.xy1.y += env->fract.cst_zoom;
		if (env->fract.area.xy2.y >= 0 && env->fract.area.xy2.y <= 1.2)
			env->fract.area.xy2.y -= env->fract.cst_zoom;
	}
	else if (key == ARROW_DOWN)
	{
	//	if (env->fract.area.xy1.y >= -1.20001 && env->fract.area.xy1.y <= 0)
			env->fract.area.xy1.y -= env->fract.cst_zoom;
	//	if (env->fract.area.xy2.y >= 0 && env->fract.area.xy2.y <= 1.20001)
			env->fract.area.xy2.y += env->fract.cst_zoom;
	}
	else if (key == ARROW_RIGHT)
	{
		if (env->fract.area.xy1.x >= 0 && env->fract.area.xy1.x <= 2.10001)
		env->fract.area.xy1.x -= env->fract.cst_zoom;
		if (env->fract.area.xy2.x <= 0 && env->fract.area.xy2.x >= -2.10001)
		env->fract.area.xy2.x += env->fract.cst_zoom;
	}
	else if (key == ARROW_LEFT)
	{
		if (env->fract.area.xy1.x >= 0 && env->fract.area.xy1.x <= 2.10001)
			env->fract.area.xy1.x += env->fract.cst_zoom;
		if (env->fract.area.xy2.x <= 0 && env->fract.area.xy2.x >= -2.10001)
			env->fract.area.xy2.x -= env->fract.cst_zoom;
	}
	ft_mandelbrot(env->fract, env);
}

static t_complex init_complex(t_fract fract, t_coord xy)
{
	t_complex	i;

	i = (t_complex) {	.c_r = xy.x / (double)fract.zoom + fract.area.xy1.x,
						.c_i = xy.y / (double)fract.zoom + fract.area.xy1.y,
						.z_r = 0, .z_i = 0};
	return (i);
}

static void calc_complex(t_fract fract, t_complex i, t_coord xy, t_env *env)
{
	double tmp;
	t_ushort a;

	a = 0;
	while (SQRT(i.z_r) + SQRT(i.z_i) < 4 && a < fract.iterate)
	{
		tmp = i.z_r;
		i.z_r = (SQRT(i.z_r) - SQRT(i.z_i) + i.c_r);
		i.z_i = 2 * i.z_i * tmp + i.c_i;
		a++;
	}
	if (a == fract.iterate)
		ft_draw_pixel(xy.x, xy.y, ft_create_rgb("000000"), env);
	else
		ft_draw_pixel(xy.x, xy.y, (t_rgb) {0, 0, a * 255 / fract.iterate}, env);
}

void	ft_mandelbrot(const t_fract fract, t_env *env)
{
	t_coord		img_xy;
	t_coord		xy;
	t_complex	i;

	xy.x = 0;
	img_xy.x = (fract.area.xy2.x - fract.area.xy1.x) * (double)fract.zoom;
	img_xy.y = (fract.area.xy2.y - fract.area.xy1.y) * (double)fract.zoom;
	env->affichage = 1;
	if (img_xy.x > env->width)
		img_xy.x = env->width;
	if (img_xy.y > env->height)
		img_xy.y = env->height;
	while (xy.x < img_xy.x)
	{
		xy.y = 0;
		while (xy.y < img_xy.y)
		{
			i = init_complex(fract, xy);
			calc_complex(fract, i, xy, env);
			xy.y++;
		}
		xy.x++;
	}
}
