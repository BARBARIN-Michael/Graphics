/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 18:24:19 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/27 17:21:23 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

double		coord_x_iso(int x, int y)
{
	return (OFFSET_ISO * x - OFFSET_ISO * y);
}

double		coord_y_iso(int x, int y, int z)
{
	return (z + (OFFSET_ISO / 2) * x + (OFFSET_ISO / 2) * y);
}

int			x_max(t_list *lst)
{
	t_list	*sv;
	int		lenx;
	int		rslt;

	lenx = 0;
	sv = lst;
	while (lst != NULL)
	{
		if (lenx < (rslt = ft_coord_nbr(lst->content)))
			lenx = rslt;
		lst = lst->next;
	}
	lst = sv;
	return (lenx);
}

int			y_max(t_list *lst)
{
	t_list	*sv;
	int		leny[2];
	int		offsety;
	int		x;
	int		rslt;

	//leny[0] = Hauteur positive
	//leny[1] = Hauteur negative
	sv = lst;
	leny[0] = 0;
	leny[1] = 0;
	offsety = 0;
	while (lst != NULL)
	{
		x = 0;
		while ((rslt = ft_getvalue(lst->content, x)) >= 0)
		{
			if (leny[0] < (rslt - offsety))
				leny[0] = rslt - offsety;
			if (leny[1] > (rslt - offsety))
				leny[1] = (rslt - offsety);
			x++;
		}
		lst = lst->next;
		offsety++;
	}
	lst = sv;
	return (leny[0] - leny[1]);
}
