/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:41:00 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/03 15:16:44 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arka.h>
#include <math.h>

void	rect_cursor(int x1)
{
	glColor3ub(0, 0, 255);
	glRecti(WIDTH_CURSOR1 + x1, HEIGHT_CURSOR1,
			WIDTH_CURSOR2 + x1, HEIGHT_CURSOR2);
	glColor3ub(255, 255, 255);
}

void	circle_ball(int cx, int cy)
{
	int		i;
	float	y;
	float	x;
	float	size_ball;

	i = 0;
	size_ball = 10;
	glBegin(GL_TRIANGLE_FAN);
	while (i < 180)
	{
		x = size_ball * cos(i);
		y = size_ball * sin(i);
		glVertex3f(x + cx, y + cy, 0);

		x = size_ball * cos(i + 0.1);
		y = size_ball * sin(i + 0.1);
		glVertex3f(x + cx, y + cy, 0);
		++i;
	}
	glEnd();
}

void	rect_block(t_coord4f coord, t_rgb rgb)
{
	glColor3ub(rgb.r, rgb.g, rgb.b);
	glRectf(coord.pt_hl_x, coord.pt_hl_y,
			coord.pt_lr_x, coord.pt_lr_y);
	glColor3ub(255, 255, 255);
}

void	create_map(t_env env)
{
	t_coord4f	coord;
	int			parse;
	float		len_block;
	float		height_block;

	len_block = env.wh.width / env.world_map->nbr_line;
	height_block = (env.wh.height / 2) / env.world_map->nbr_line;
}
