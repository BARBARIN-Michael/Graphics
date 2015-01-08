/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 10:29:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/08 21:11:02 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

static color getcolor(int height)
{
		if (height <= -1 && height > -15)
			return (ft_strtol("3A5256"));
		if (height <= -15)
			return (ft_strtol("004656"));
		if (height > -14 && height < 25)
			return (0x0B6D04);
		if (height >= 25 && height <= 299)
			return (0x3F6D20);
		if (height > 300)
			return (0xFFFFFF);
		else
			return (0xFFFFFF);
}

static void	testdirector(t_vector vec1, int *xincr, int *yincr)
{
	if(vec1.x1 < vec1.x2)
		*xincr = 1;
	else
		*xincr = -1;
	if(vec1.y1 < vec1.y2)
		*yincr = 1;
	else
		*yincr = -1;
}

static void first_type(t_cline *cl, char *col, t_env *env, int height)
{
	int		i;
	color coltodraw;

	i = 0;
	cl->error = cl->deltax / 2;
	while (i < cl->deltax)
	{
		cl->xy.x += cl->xincr;
		cl->error += cl->deltay;
		if(cl->error > cl->deltax)
		{
			cl->error -= cl->deltax;
			cl->xy.y += cl->yincr;
		}
		if (ft_strtol(col) == 0x000000)
			coltodraw = getcolor(height);
		else
			coltodraw = ft_strtol(col);
		draw_pixel_to_img(cl->xy.x, cl->xy.y, coltodraw, env);
		i++;
	}
}

static void second_type(t_cline *cl, char *col, t_env *env, int height)
{
	int		i;
	color coltodraw;

	i = 0;
	cl->error = cl->deltay / 2;
	while (i < cl->deltay)
	{
		cl->xy.y += cl->yincr;
		cl->error += cl->deltax;
		if(cl->error > cl->deltay)
		{
			cl->error -= cl->deltay;
			cl->xy.x += cl->xincr;
		}
		if (ft_strtol(col) == 0x000000)
			coltodraw = getcolor(height);
		else
			coltodraw = ft_strtol(col);
		draw_pixel_to_img(cl->xy.x, cl->xy.y, coltodraw, env);
		i++;
	}
}

void draw_line1(t_vector vec1, t_env *env, char *col, char* offcol)
{
	t_cline cl;

	offcol = offcol;
	cl.deltax = abs(vec1.x2 - vec1.x1);
	cl.deltay = abs(vec1.y2 - vec1.y1);
	testdirector(vec1, &cl.xincr, &cl.yincr);
	cl.xy.x = vec1.x1;
	cl.xy.y = vec1.y1;
	if (cl.deltax > cl.deltay)
		first_type(&cl, col, env, vec1.alt);
	else
		second_type(&cl, col, env, vec1.alt);
	draw_pixel_to_img(cl.xy.x, cl.xy.y, ft_strtol(col), env);
}
