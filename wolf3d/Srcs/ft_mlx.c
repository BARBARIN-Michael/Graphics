/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 14:55:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <mlx.h>

void	ft_init_mlx(t_env *env)
{
	if (!(env->mlx.mlx_ptr = mlx_init()))
		ft_error("MLX cannot initialized", "init X10.1", 1);
	env->mlx.img = mlx_new_image(env->mlx.mlx_ptr, env->width, env->height);
	env->mlx.win_ptr = mlx_new_window(env->mlx.mlx_ptr, env->width, env->height,
			env->title);
	env->mlx.data = mlx_get_data_addr(env->mlx.img, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
}

void	ft_putimage(t_env *env)
{
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr, env->mlx.img,
			0, 0);
}

void	ft_newcalcul(t_env *env, )
{
	return ;
}
