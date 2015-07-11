/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:39:47 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 14:40:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static t_rgb	ft_setup_color(t_ushort type_color)
{
	t_rgb	rgb[17];

	rgb[0] = (t_rgb) {0x57, 0x2B, 0x06};
	rgb[1] = (t_rgb) {.r = 0x70, .g = 0x38, .b = 0x08};
	rgb[2] = (t_rgb) {.r = 0xA6, .g = 0x53, .b = 0x0C};
	rgb[3] = (t_rgb) {.r = 0xD6, .g = 0xA7, .b = 0x1D};
	rgb[4] = (t_rgb) {.r = 0x57, .g = 0x2B, .b = 0xb6};
	rgb[5] = (t_rgb) {.r = 0xD6, .g = 0x8D, .b = 0x1D};
	rgb[6] = (t_rgb) {.r = 0xA0, .g = 0x8D, .b = 0x1D};
	rgb[7] = (t_rgb) {.r = 0x69, .g = 0x8D, .b = 0x1D};
	rgb[8] = (t_rgb) {.r = 0xB8, .g = 0x94, .b = 0x88};
	rgb[9] = (t_rgb) {.r = 0x8A, .g = 0x94, .b = 0x88};
	rgb[10] = (t_rgb) {.r = 0x5A, .g = 0x94, .b = 0x88};
	rgb[11] = (t_rgb) {.r = 0x07, .g = 0x94, .b = 0x88};
	rgb[12] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x1C};
	rgb[13] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x3F};
	rgb[14] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x63};
	rgb[15] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0xA8};
	if (type_color > 15)
		type_color = 16;
	rgb[16] = (t_rgb) {.r = 0xFF, .g = 0xFF, .b = 0xFF};
	return (rgb[type_color]);
}

t_rgb			ft_get_color_by_pt(int map_elem, int mod, t_move data)
{
	t_rgb rgb;

	if (data.wall_hor == TRUE && data.stape.y == 1)
		rgb = ft_setup_color((map_elem - 1));
	else if (data.wall_hor == TRUE && data.stape.y == -1)
		rgb = ft_setup_color((map_elem - 1) + 4);
	else if (data.wall_hor == FALSE && data.stape.x == 1)
		rgb = ft_setup_color((map_elem - 1) + 8);
	else if (data.wall_hor == FALSE && data.stape.x == -1)
		rgb = ft_setup_color((map_elem - 1) + 12);
	else
		rgb = ft_setup_color(map_elem);
	rgb = (t_rgb) {.r = rgb.r / mod, .g = rgb.g / mod, .b = rgb.b / mod};
	return (rgb);
}

void			ft_color_tile(t_env *env, t_move *data, int tabi)
{
	t_rgb		rgb;
	t_datacam	*cam;
	int			tiles;
	int			tabimg;

	cam = env->datacam;
	tiles = env->world_map->line[cam->coord_map.x][cam->coord_map.y];
	tabimg = ((data->texture.y * env->mlx.img[tiles].sizeline)
			+ (data->texture.x * 4));
	rgb.b = env->mlx.img[tiles].data[tabimg + 0];
	rgb.g = env->mlx.img[tiles].data[tabimg + 1];
	rgb.r = env->mlx.img[tiles].data[tabimg + 2];
	env->mlx.img[0].data[tabi + 0] = rgb.b;
	env->mlx.img[0].data[tabi + 1] = rgb.g;
	env->mlx.img[0].data[tabi + 2] = rgb.r;
}

static void		ft_color_wall(t_env *env, t_move *data, t_floor calc)
{
	t_rgb		rgb;
	t_coord		xy;
	int			tabi[2];

	xy = (t_coord){.y = env->wh.height - calc.y, .x = calc.x};
	tabi[0] = ((calc.texture.y * env->mlx.img[5].sizeline)
				+ (calc.texture.x * 4));
	tabi[1] = ((xy.y * env->mlx.img[0].sizeline) + (xy.x * 4));
	rgb.b = env->mlx.img[5].data[tabi[0] + 0];
	rgb.g = env->mlx.img[5].data[tabi[0] + 1];
	rgb.r = env->mlx.img[5].data[tabi[0] + 2];
	env->mlx.img[0].data[tabi[1] + 0] = rgb.b;
	env->mlx.img[0].data[tabi[1] + 1] = rgb.g;
	env->mlx.img[0].data[tabi[1] + 2] = rgb.r;
}

void			ft_color_floor(t_env *env, t_move *data, t_floor calc)
{
	t_rgb		rgb;
	int			tabi[2];
	t_coord		xy;

	xy = (t_coord){.y = calc.y, .x = calc.x};
	tabi[0] = ((calc.texture.y * env->mlx.img[4].sizeline)
				+ (calc.texture.x * 4));
	tabi[1] = ((xy.y * env->mlx.img[0].sizeline) + (xy.x * 4));
	if (tabi[0] < 0)
		return ;
	rgb.b = env->mlx.img[4].data[tabi[0] + 0];
	rgb.g = env->mlx.img[4].data[tabi[0] + 1];
	rgb.r = env->mlx.img[4].data[tabi[0] + 2];
	env->mlx.img[0].data[tabi[1] + 0] = rgb.b;
	env->mlx.img[0].data[tabi[1] + 1] = rgb.g;
	env->mlx.img[0].data[tabi[1] + 2] = rgb.r;
	ft_color_wall(env, data, calc);
}
