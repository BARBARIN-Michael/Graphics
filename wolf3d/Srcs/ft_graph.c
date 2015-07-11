/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 18:59:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <time.h>

void	ft_graph(t_env *env)
{
	ft_putimage(env, env->mlx.img);
}

void	ft_putimage(t_env *env, t_img *img)
{
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
			img[0].img, 0, -1);
	ft_putweapon(env);
}
