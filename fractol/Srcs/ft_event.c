/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 14:41:52 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/02 21:49:07 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

int		ft_event_mouse(int button, int x, int y, t_env *env)
{
	if (button == 4)
		ft_zoom_mandelbrot(x, y, env);
	if (button == 1)
		env->fract.iterate += 50;
	return (0);
}
int		ft_event_key(int key, t_env *env)
{
	if (key == KEY_ESCAPE)
		ft_exit(&env->mlx);
	else if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_RIGHT || key == ARROW_LEFT)
		ft_move_mandelbrot(key, env);
	else if (key == 113)
		printf(C_GREEN"On lit les donnees : zoom{%d}, iterate{%d} X1{%f} X2{%f} Y1{%f} Y2{%f}"C_NONE"\n", env->fract.zoom, env->fract.iterate, env->fract.area.xy1.x, env->fract.area.xy2.x, env->fract.area.xy1.y, env->fract.area.xy2.y);
	else if (key == 49)
		env->fract.cst_zoom = 0.5;
	else if (key == 50)
		env->fract.cst_zoom = 0.1;
	else if (key == 51)
		env->fract.cst_zoom = 0.01;
	else if (key == 52)
		env->fract.cst_zoom = 0.001;
	else if (key == 48)
	{
		ft_bzero(env->mlx.data, env->mlx.sizeline * env->height);
		ft_bzero(env->mlx.data_tmp, env->mlx.sizeline * env->height);
		ft_mandelbrot(env->fract, env);
	}
	printf(C_GREEN"On lit les donnees : key{%d}\n", key);
	return (0);
}
int			ft_event_expose(t_env *env)
{
	ft_icd_mlx(env, "put");
	return (0);
}
