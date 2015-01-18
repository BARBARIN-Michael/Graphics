/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 19:41:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

void			exit_fdf(t_node *map, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	map = map;
	ft_del_map(&map);
	exit(0);
}

void			ft_icd_mlx(t_env *env, int state)
{
	if (state == 0)
	{
		env->mlx.mlx_ptr = mlx_init();
		env->mlx.img = mlx_new_image(env->mlx.mlx_ptr, env->width,
				env->height);
		env->mlx.win_ptr = mlx_new_window(env->mlx.mlx_ptr, env->width,
				env->height, TITLE_WIN);
	}
	else if (state == 1)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img, 0, 0);
	else if (state == 2)
	{
		mlx_destroy_image(env->mlx.mlx_ptr, env->mlx.img);
		env->mlx.img = mlx_new_image(env->mlx.mlx_ptr, env->width,
				env->height);
		env->mlx.data = mlx_get_data_addr(env->mlx.img, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
	}
}

void			ft_fdf(char *str, int width, int height, int mode)
{
	t_env		env;

	env = (t_env) {.dx = 1, .dy = 1, .height = height, .width = width,
		.w = (width / 3) - 100, .h = (height / 3), .prof = 0, .proj = 0};
	env.mlx.modes = mode;
	env.map = ft_parsefile(str);
	if (width == 0 || height == 0)
	{
		env.width = ft_win_lenghtw(lenght_x_map(&env.map));
		env.height = ft_win_lenghth(lenght_y_map(&env.map));
	}
	if (lenght_x_map(&env.map) < (env.width / 10))
	{
		env.dy = (env.height - env.height / 3) / lenght_y_map(&env.map);
		env.dx = env.dy;
		env.prof = 5;
	}
	ft_icd_mlx(&env, 0);
	mlx_key_hook (env.mlx.win_ptr, ft_event_key, &env);
	mlx_expose_hook(env.mlx.win_ptr, ft_event_expose, &env);
	mlx_loop(env.mlx.mlx_ptr);
}

int				lenght_y_map(t_node **map)
{
	t_node			*c_right;
	static int		cmp = 0;

	if (cmp != 0)
		return (cmp);
	cmp = 1;
	c_right = *map;
	while (c_right)
	{
		cmp++;
		c_right = c_right->next;
	}
	return (cmp);
}

int				lenght_x_map(t_node **map)
{
	t_node			*c_left;
	static int		cmp = 0;

	if (cmp != 0)
		return (cmp);
	c_left = *map;
	cmp = c_left->elem;
	return (cmp);
}
