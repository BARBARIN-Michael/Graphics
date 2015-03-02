/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 14:41:52 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/28 20:36:22 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

void		ft_event_mouse(int key, t_env *env)
{
	key = key;
	env = env;
	exit(0);
}

int			ft_event_expose(t_env *env)
{
	ft_icd_mlx(env, "put");
	return (0);
}
