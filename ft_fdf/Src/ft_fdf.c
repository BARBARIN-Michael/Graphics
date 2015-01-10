/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/10 12:19:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../Include/ft_fdf.h"

void			exit_fdf(t_node *map, t_mlx *mlx)
{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_del_map(&map);
		exit(0);
}

void			ft_icd_mlx(t_mlx *mlx, int state, int width, int height)
{
	void	*img;
	int		wh[2];

	wh[0] = width;
	wh[1] = height;
	if (state == 0)
	{
		mlx->mlx_ptr = mlx_init();
		mlx->img = mlx_new_image(mlx->mlx_ptr, wh[0], wh[1]);
		mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->sizeline, &mlx->endian);
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, wh[0], wh[1], TITLE_WIN);
	}
	else if (state == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	else if (state == 2)
	{
		img = mlx->img;
		mlx->img = mlx_new_image(mlx->mlx_ptr, wh[0], wh[1]);
		mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->sizeline, &mlx->endian);
		mlx_destroy_image(mlx->mlx_ptr, img);
	}
}

void			ft_fdf(char *str, int width, int height)
{
	t_env		env;
	int			cmp_node;

	env = (t_env) {.dx = cmp_node, .dy = cmp_node, .prof = 3,
		.w = (width / 2) - 100, .h = (height / 4), .prof = 0,
		.mlx.width = width, .mlx.height = height };
	env.map = ft_parsefile(str);
	ft_icd_mlx(&env.mlx, 0, width, height);
	cmp_node = lenght_map(&env.map);
	env.dx = (width / cmp_node) * 0.82;
	env.dy = (height / cmp_node) * 0.82;
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
