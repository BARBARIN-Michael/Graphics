/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 10:29:35 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/05 00:43:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

void draw_line1(t_vector vec1, t_env *env, color col, color offcol)
{
	int x,y;
	int Dx,Dy;
	int xincr,yincr;
	int erreur;
	int i;

	Dx = abs(vec1.x2-vec1.x1);
	Dy = abs(vec1.y2-vec1.y1);
	if(vec1.x1<vec1.x2)
		xincr = 1;
	else
		xincr = -1;
	if(vec1.y1<vec1.y2)
		yincr = 1;
	else
		yincr = -1;

	x = vec1.x1;
	y = vec1.y1;
	if(Dx>Dy)
	{
		erreur = Dx/2;
		for(i=0;i<Dx;i++)
		{
			x += xincr;
			erreur += Dy;
			if(erreur>Dx)
			{
				erreur -= Dx;
				y += yincr;
			}
			draw_pixel_to_img(x, y, col + (i *3 + (0xA2A2A2 | offcol)), env);
		}
	}
	else
	{
		erreur = Dy/2;
		for(i=0;i<Dy;i++)
		{
			y += yincr;
			erreur += Dx;
			if(erreur>Dy)
			{
				erreur -= Dy;
				x += xincr;
			}
			draw_pixel_to_img(x, y, col + (i * 2 + (0xA2A2A2 | offcol)), env);
			//draw_pixel_to_img(x, y, col + (x * 0x222222), env);
		}
	}
	draw_pixel_to_img(x, y, col /*+ (i * 2 + (0xA2A2A2 | offcol))*/, env);
	//draw_pixel_to_img(x, y, col + (x * 0xF42AB2), env);
}
