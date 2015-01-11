/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 10:29:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/11 14:15:43 by mbarbari         ###   ########.fr       */
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

static void first_type(t_cline *cl, char **col, t_env *env, int h)
{
	int				i;
	t_rgb			coltodraw;
	static t_rgb	oc;

	i = -1;
	cl->error = cl->dx / 2;
	while (++i < cl->dx)
	{
		cl->xy.x += cl->xincr;
		cl->error += cl->dy;
		if(cl->error > cl->dx)
		{
			cl->error -= cl->dx;
			cl->xy.y += cl->yincr;
		}
		if (ft_strtol(col[0]) == 0x000000 && env->mlx.modes == 1)
			coltodraw = getshaded(getcolormap(h, &env->map), oc, cl->dx, i);
		else if (ft_strtol(col[0]) != 0x000000)
			coltodraw = getcolorbydegrade(col, cl->dy, i);
		else
			coltodraw = create_rgb("FFFFFF");
		draw_pixel_to_img(cl->xy.x, cl->xy.y, coltodraw, env);
		oc = coltodraw;
	}
}

static void second_type(t_cline *cl, char **col, t_env *env, int h)
{
	int				i;
	t_rgb			coltodraw;
	static t_rgb	oc;

	i = -1;
	cl->error = cl->dy / 2;
	while (++i < cl->dy)
	{
		cl->xy.y += cl->yincr;
		cl->error += cl->dx;
		if(cl->error > cl->dy)
		{
			cl->error -= cl->dy;
			cl->xy.x += cl->xincr;
		}
		if (ft_strtol(col[0]) == 0x000000 && env->mlx.modes == 1)
			coltodraw = getshaded(getcolormap(h, &env->map), oc, cl->dy, i);
		else if (ft_strtol(col[0]) != 0x000000)
			coltodraw = getcolorbydegrade(col, cl->dy, i);
		else
			coltodraw = create_rgb("FFFFFF");
		draw_pixel_to_img(cl->xy.x, cl->xy.y, coltodraw, env);
		oc = coltodraw;
	}
}

void draw_line1(t_vector vec1, t_env *env, char *col, char* offcol)
{
	t_cline	cl;
	char	*colglob[2];

	colglob[0] = col;
	colglob[1] = offcol;
	cl.dx = abs(vec1.x2 - vec1.x1);
	cl.dy = abs(vec1.y2 - vec1.y1);
	testdirector(vec1, &cl.xincr, &cl.yincr);
	cl.xy.x = vec1.x1;
	cl.xy.y = vec1.y1;
	if (cl.dx > cl.dy)
		first_type(&cl, colglob, env, vec1.alt);
	else
		second_type(&cl, colglob, env, vec1.alt);
	draw_pixel_to_img(cl.xy.x, cl.xy.y, create_rgb(col), env);
}
