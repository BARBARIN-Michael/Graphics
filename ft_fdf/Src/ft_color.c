/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:36:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/10 18:37:47 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

t_rgb		getcolorbydegrade(char **color, int delta, int idelta)
{
	long	color1;
	long	color2;
	t_rgb	rgb[3];
	color1 = ft_strtol(color[0]);
	color2 = ft_strtol(color[1]);
	rgb[0].r = ((color1 & 0xFF0000) >> 16);
	rgb[0].g = ((color1 & 0xFF00) >> 8);
	rgb[0].b = (color1 & 0xFF);
	rgb[1].r = ((color2 & 0xFF0000) >> 16);
	rgb[1].g = ((color2 & 0xFF00) >> 8);
	rgb[1].b = (color2 & 0xFF);
	if (delta > 0)
	{
		rgb[2].r = rgb[0].r + (rgb[0].r - rgb[1].r) * (idelta / delta);
		rgb[2].g = rgb[0].g + (rgb[0].g - rgb[1].g) * (idelta / delta);
		rgb[2].b = rgb[0].b + (rgb[0].b - rgb[1].b) * (idelta / delta);
		return (rgb[2]);
	}
	return (rgb[0]);
}

t_rgb		getshaded(t_rgb rgb1, t_rgb rgb2, int delta, int idelta)
{
	t_rgb	rgb[3];

	rgb[0] = rgb1;
	rgb[1] = rgb2;
	rgb[2].r = rgb[0].r + (rgb[0].r - rgb[1].r) * (idelta / delta);
	rgb[2].g = rgb[0].g + (rgb[0].g - rgb[1].g) * (idelta / delta);
	rgb[2].b = rgb[0].b + (rgb[0].b - rgb[1].b) * (idelta / delta);
	return (rgb[2]);
}

t_rgb		getcolormap(int height, t_node **map)
{
	static int		*heightpos_neg;
	t_rgb			coltosend;

	if (heightpos_neg == NULL)
		heightpos_neg = ft_map_height(map);

	if (height >= floor((9.0 / 10.0) * (double)heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0xFF, .g = 0xFF, .b = 0xFF};
	else  if (height <= floor((9.0 / 10.0) * (double)heightpos_neg[0])
				&& height > floor(((8.0 / 10.0) * (double)heightpos_neg[0])))
		coltosend = (t_rgb) {.r = 0x6D, .g = 0x57, .b = 0x56};
	else  if (height <= floor((8.0 / 10.0) * (double)heightpos_neg[0])
				&& height > floor((5.0 / 10.0) * (double)heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0x6D, .g = 0x55, .b = 0x20};
	else  if (height <= floor((5.0 / 10.0) * (double)heightpos_neg[0])
				&& height > floor((2.0 / 10.0) * (double)heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0x48, .g = 0x6D, .b = 0x32};
	else  if (height <= floor(((2.0 / 10.0) * (double)heightpos_neg[0]))
				&&  height >= 0)
		coltosend = (t_rgb) {.r = 0x0A, .g = 0x6D, .b = 0x21};
	else  if (height > floor((7 / 10) * (double)heightpos_neg[1]))
		coltosend = (t_rgb) {.r = 0x67, .g = 0x75, .b = 0xE8};
	else  if (height <= floor((7 / 10) * (double)heightpos_neg[1]))
		coltosend = (t_rgb) {.r = 0x32, .g = 0x25, .b = 0x9C};
	else
		coltosend = (t_rgb) {.r = 0x00, .g = 0x00, .b = 0x00};
	return (coltosend);
}

t_rgb		create_rgb(char *col)
{
	t_rgb	rgbtosend;
	color	collu;

	collu = ft_strtol(col);
	rgbtosend.r = (collu & 0xFF0000) >> 16;
	rgbtosend.g = (collu & 0xFF00) >>  8;
	rgbtosend.b = (collu & 0xFF);
	return (rgbtosend);
}
