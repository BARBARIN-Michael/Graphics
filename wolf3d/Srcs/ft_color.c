/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:39:47 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 01:56:46 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static t_rgb	ft_setup_color(t_ushort type_color)
{
	t_rgb	rgb[17];
	//Nord
	rgb[0] = (t_rgb) {0x57, 0x2B, 0x06};
	rgb[1] = (t_rgb) {.r = 0x70, .g = 0x38, .b = 0x08};
	rgb[2] = (t_rgb) {.r = 0xA6, .g = 0x53, .b = 0x0C};
	rgb[3] = (t_rgb) {.r = 0xD6, .g = 0xA7, .b = 0x1D};
	//Sud
	rgb[4] = (t_rgb) {.r = 0x57, .g = 0x2B, .b = 0x06};
	rgb[5] = (t_rgb) {.r = 0xD6, .g = 0x8D, .b = 0x1D};
	rgb[6] = (t_rgb) {.r = 0xA0, .g = 0x8D, .b = 0x1D};
	rgb[7] = (t_rgb) {.r = 0x69, .g = 0x8D, .b = 0x1D};
	//Est
	rgb[8] = (t_rgb) {.r = 0xB8, .g = 0x94, .b = 0x88};
	rgb[9] = (t_rgb) {.r = 0x8A, .g = 0x94, .b = 0x88};
	rgb[10] = (t_rgb) {.r = 0x5A, .g = 0x94, .b = 0x88};
	rgb[11] = (t_rgb) {.r = 0x07, .g = 0x94, .b = 0x88};
	//OUEST
	rgb[12] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x1C};
	rgb[13] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x3F};
	rgb[14] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x63};
	rgb[15] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0xA8};
	//Defaut
	if (type_color > 15)
		type_color = 16;
	rgb[16] = (t_rgb) {.r = 0xFF, .g = 0xFF, .b = 0xFF};
	return (rgb[type_color]);
}

t_rgb			ft_get_color_by_pt(int map_elem, int mod)
{
	t_rgb rgb;

	rgb = ft_setup_color(map_elem);
	rgb = (t_rgb) {.r = rgb.r / mod, .g = rgb.g / mod, .b = rgb.b / mod};
	return (rgb);
}
