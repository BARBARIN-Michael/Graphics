/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/02 19:20:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void			ft_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void			ft_icd_mlx(t_env *env, const char *state)
{
	void	*img_switch;
	char	*data_switch;

	if (ft_strcmp(state, "initialize") == 0)
	{
		env->mlx.mlx_ptr = mlx_init();
		env->mlx.img = mlx_new_image(env->mlx.mlx_ptr, env->width,
				env->height);
		env->mlx.img_tmp = mlx_new_image(env->mlx.mlx_ptr, env->width,
				env->height);
		env->mlx.win_ptr = mlx_new_window(env->mlx.mlx_ptr, env->width,
				env->height, env->title);
		env->mlx.data = mlx_get_data_addr(env->mlx.img, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
		env->mlx.data_tmp = mlx_get_data_addr(env->mlx.img_tmp, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
	}
	else if (ft_strcmp(state, "put") == 0)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img, 0, 0);
	else if (ft_strcmp(state, "new calcul") == 0)
	{
		img_switch = env->mlx.img;
		data_switch = env->mlx.data;
		env->mlx.img = env->mlx.img_tmp;
		env->mlx.data = env->mlx.data_tmp;
		env->mlx.img_tmp = img_switch;
		env->mlx.data_tmp = data_switch;
		ft_bzero(env->mlx.data_tmp, env->mlx.sizeline * env->height);
		ft_icd_mlx(env, "put");
	}
}

static t_fcts_fractal	setup_ptrfcts(const char *fractal)
{
	t_fcts_fractal fcts;
	if (ft_strcmp(fractal, "mandelbrot") == 0)
		fcts = &ft_mandelbrot;
	else
		exit(0);
	return (fcts);
}

static t_fract init_fract(t_ushort iterate, t_ushort zoom)
{
	t_fract fract;

	fract.iterate = iterate;
	fract.zoom = zoom;
	fract.area.xy1.x = -2.1;
	fract.area.xy2.x = 0.6;
	fract.area.xy1.y = -1.2;
	fract.area.xy2.y = 1.2;
	return (fract);
}
void			ft_exec(char *title, int width, int height, const char *fractal)
{
	t_env		env;

	env = (t_env) {	.width = width, .height = height, .title = title,
					.affichage = 1};
	env.fcts = setup_ptrfcts(fractal);
	ft_icd_mlx(&env, "initialize");
	env.fract = init_fract(50, 100);
	env.fcts(env.fract, &env);
//	mlx_expose_hook(env.mlx.win_ptr, ft_event_expose, &env);
	mlx_mouse_hook(env.mlx.win_ptr, ft_event_mouse, &env);
	mlx_key_hook(env.mlx.win_ptr, ft_event_key, &env);
	mlx_loop_hook(env.mlx.mlx_ptr, ft_event_fractal, &env);
	mlx_loop(env.mlx.mlx_ptr);
}
