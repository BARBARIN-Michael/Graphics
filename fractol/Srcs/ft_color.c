/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:36:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/28 22:23:54 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

t_rgb		ft_create_rgb(char *col)
{
	t_rgb	rgbtosend;
	t_color	collu;

	collu = ft_strtol(col);
	rgbtosend.r = (collu & 0xFF0000) >> 16;
	rgbtosend.g = (collu & 0xFF00) >> 8;
	rgbtosend.b = (collu & 0xFF);
	return (rgbtosend);
}
