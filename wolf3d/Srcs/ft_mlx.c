/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/17 12:39:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <mlx.h>

void	ft_init_mlx(t_env *env)
{
	t_screen wh;

	wh = env->wh;
	if (!(env->mlx.mlx_ptr = mlx_init()))
		ft_error("MLX cannot initialized", "init X10.1", 1);
	env->mlx.img = mlx_new_image(env->mlx.mlx_ptr, wh.width, wh.height);
	env->mlx.img_map = mlx_new_image(env->mlx.mlx_ptr,
			(env->map_max.x - 1) * env->nb_px,
			(env->map_max.y + 1) * env->nb_px);
	env->mlx.win_ptr = mlx_new_window(env->mlx.mlx_ptr, wh.width, wh.height,
			env->title);
	env->mlx.data = mlx_get_data_addr(env->mlx.img, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
	env->mlx.data_map = mlx_get_data_addr(env->mlx.img_map, &env->mlx.bpp,
			&env->mlx.sizemap, &env->mlx.endian);
}

void	ft_putimage(t_env *env, void *img)
{
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr, img,
			0, 0);	
	if (env->map == 1)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img_map, 0, 0);
}
