/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 16:14:16 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/02 16:53:24 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

int	ft_event_fractal(t_env *env)
{
	if (env->affichage == 1)
		ft_icd_mlx(env, "new calcul");
	env->affichage = 0;
	return (0);
}
