/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/12 19:04:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

void			exit_fdf(t_node *map, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
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
		env->mlx.data = mlx_get_data_addr(env->mlx.img, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
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
	int			cmp_node;

	env = (t_env) {.dx = 2, .dy = 2,
		.w = (width / 2) - 100, .h = (height / 4), .prof = 0, .proj = 0,
		.width = width, .height = height };
	env.mlx.modes = mode;
	env.map = ft_parsefile(str);
	cmp_node = lenght_map(&env.map);
	if (cmp_node < (width / 10))
	{
		env.dx = (width - width / 2) / cmp_node;
		env.dy = env.dx;
		env.prof = 10;
	}
	ft_icd_mlx(&env, 0);
	mlx_expose_hook(env.mlx.win_ptr, ft_event_expose, &env);
	mlx_key_hook (env.mlx.win_ptr, ft_event_key, &env);
	mlx_loop(env.mlx.mlx_ptr);
}

int				lenght_map(t_node **map)
{
	t_node	*c_left;
	int		cmp;

	cmp = 0;
	c_left = *map;
	while (c_left)
	{
		cmp++;
		c_left = c_left->left_node;
	}
	return (cmp);
}
