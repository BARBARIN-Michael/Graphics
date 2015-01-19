/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:23:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 00:04:01 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "../Include/ft_fdf.h"

int ft_win_lenghtw(int cmp_node)
{
	int width;

	width = (WIDTH * cmp_node);
	if (width > 2500)
		width = 2500;
	return (width);
}

int ft_win_lenghth(int cmp_node)
{
	int height;

	height = (HEIGHT * cmp_node);
	if (height > 1400)
		height = 1400;
	return (height);
}
