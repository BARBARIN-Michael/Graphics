/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algofdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 18:24:19 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/29 11:04:23 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

double		coord_x_iso(int x, int y)
{
	return (OFFSET_ISOX * x - OFFSET_ISOY * y);
}

double		coord_y_iso(int x, int y, int z)
{
	return (z + (OFFSET_ISOX / 2) * x + (OFFSET_ISOY / 2) * y);
}

int			x_max(t_list *lst)
{
	int		lenx;
	int		rslt;

	lenx = 0;
	while (lst != NULL)
	{
		if (lenx < (rslt = ft_coord_nbr(lst->content)))
			lenx = rslt;
		lst = lst->next;
	}
	return (lenx);
}

int			y_max(t_list *lst)
{
	int		leny_pos;
	int		leny_neg;
	int		offsety;
	int		x;
	int		rslt;

	leny_pos = 0;
	leny_neg = 0;
	x = 0;
	offsety = 0;
	while (lst != NULL)
	{
		while ((rslt = ft_getValue(lst->content, x)) >= 0)
		{
			if (leny_pos < (rslt - offsety))
				leny_pos = rslt - offsety;
			if (leny_neg > (rslt - offsety))
				leny_neg = (rslt - offsety);
		}
		lst = lst->next;
		offsety++;
	}
	return (leny_pos - leny_neg);
}
