/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:36:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 23:04:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

t_rgb		getcolorbydegrade(char **color, int delta, int idelta)
{
	long int	color1;
	long int	color2;
	t_rgb		rgb[3];
	t_rgb		rgb1;

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
		rgb1 = rgb[2];
		return (rgb1);
	}
	rgb1 = rgb[0];
	return (rgb1);
}

t_rgb		getshaded(t_rgb rgb1, t_rgb rgb2, double percent)
{
	t_rgb	rgb[3];

	rgb[0] = rgb1;
	rgb[1] = rgb2;
	rgb[2].r = rgb[0].r + (rgb[0].r - rgb[1].r) * percent;
	rgb[2].g = rgb[0].g + (rgb[0].g - rgb[1].g) * percent;
	rgb[2].b = rgb[0].b + (rgb[0].b - rgb[1].b) * percent;
	return (rgb[2]);
}

t_rgb		getcolormap(double height, t_node **map)
{
	int				*heightpos_neg;
	t_rgb			coltosend;

	heightpos_neg = ft_map_height(map);
	if (height >= ((5.5 / 10.0) * heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0xFF, .g = 0xFF, .b = 0xFF};
	else if (height < ((5.5 / 10.0) * heightpos_neg[0])
				&& height > (((4.0 / 10.0) * heightpos_neg[0])))
		coltosend = (t_rgb) {.r = 0x6D, .g = 0x57, .b = 0x56};
	else if (height <= ((4.0 / 10.0) * heightpos_neg[0])
				&& height > ((1.5 / 10.0) * heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0x6D, .g = 0x55, .b = 0x20};
	else if (height <= ((1.5 / 10.0) * heightpos_neg[0])
				&& height > ((1.0 / 10.0) * heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0x48, .g = 0x6D, .b = 0x32};
	else if (height <= (((1.0 / 10.0) * heightpos_neg[0]))
				&& height > ((0.1 / 10.0) * heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0x0A, .g = 0x6D, .b = 0x21};
	else if (height >= ((0.0 / 10) * heightpos_neg[0]))
		coltosend = (t_rgb) {.r = 0x00, .g = 0xA5, .b = 0x21};
	else if (height >= ((10 / 10) * heightpos_neg[1]))
		coltosend = (t_rgb) {.r = 0x32, .g = 0x25, .b = 0x9C};
	return (coltosend);
}

t_rgb		getcolormap2(double height)
{
	t_rgb			coltosend;

	if (height >= (90.0 / 100))
		coltosend = (t_rgb) {.r = 0x55, .g = 0x00, .b = 0x00};
	else if (height <= (90.0 / 100)
				&& height > (80 / 100))
		coltosend = (t_rgb) {.r = 0x00, .g = 0x55, .b = 0x20};
	else if (height <= (80.0 / 100.0)
				&& height > (70.0 / 100.0))
		coltosend = (t_rgb) {.r = 0x00, .g = 0x25, .b = 0x55};
	else if (height <= (70.0 / 100.0)
				&& height > (60.0 / 100))
		coltosend = (t_rgb) {.r = 0x25, .g = 0xDD, .b = 0x11};
	else if (height <= (50.0 / 100.0)
				&& height > (40.0 / 100.0))
		coltosend = (t_rgb) {.r = 0xDD, .g = 0x6A, .b = 0x4B};
	else if (height <= (40.0 / 100.0)
				&& height > (30.0 / 100.0))
		coltosend = (t_rgb) {.r = 0x4B, .g = 0xDD, .b = 0x6A};
	else if (height <= (30.0 / 100.0)
				&& height > (20.0 / 100.0))
		coltosend = (t_rgb) {.r = 0xAA, .g = 0x25, .b = 0x55};
	else if (height >= 0 && height <= (20.0 / 100.0))
		coltosend = (t_rgb) {.r = 0x6A, .g = 0x4B, .b = 0xDD};
	return (coltosend);
}

t_rgb		create_rgb(char *col)
{
	t_rgb	rgbtosend;
	t_color	collu;

	collu = ft_strtol(col);
	rgbtosend.r = (collu & 0xFF0000) >> 16;
	rgbtosend.g = (collu & 0xFF00) >> 8;
	rgbtosend.b = (collu & 0xFF);
	return (rgbtosend);
}
