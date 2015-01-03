/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/03 06:31:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../Include/ft_fdf.h"

static void exit_fdf(t_node *map, t_mlx *mlx)
{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_del_map(&map);
}

static void		ft_icd_mlx(t_mlx *mlx, t_node *map, int state)
{
	if (state == 0)
	{
		ft_putendl_c("test", "red");
		mlx->mlx_ptr = mlx_init();
		ft_putendl_c("test", "red");
		exit(0);
		mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->sizeline, &mlx->endian);
	}
	else
	{
		ft_putendl_c("test affichage", "green");
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, TITLE_WIN);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	}
}

void	ft_fdf(char *str)
{
	t_env		env;

	env = (t_env) {.dx = 1, .dy = 1, .prof = 1,
		.w = (WIDTH / 2), .h = (HEIGHT / 2)};
	env.map = ft_parsefile(str);
	ft_icd_mlx(&env.mlx, env.map, 0);
	mlx_key_hook (env.mlx.win_ptr, ft_event_key, &env);
	mlx_loop(env.mlx.mlx_ptr);
	ft_icd_mlx(&env.mlx, env.map, 1);
}
