/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 14:41:52 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/03 23:45:22 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

int		ft_event_key(int key, t_env *env)
{
	if (env)
	{
		if (key == 65307)
			exit_fdf(env->map, &env->mlx);
	}
	printf("evenement clavier appuye : %d\n", key);
	return (0);
}

int		ft_event_expose(t_env *env)
{
	draw_fdf(env);
	return (0);
}
