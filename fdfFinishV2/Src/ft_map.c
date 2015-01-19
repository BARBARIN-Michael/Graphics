/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:12:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 22:38:42 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

void		ft_del_map(t_node **map)
{
	t_node *first;
	t_node *temp;

	first = *map;
	while (first)
	{
		temp = first->next;
		free(first->tabz);
		free(first->col);
		free(first);
		first = temp;
	}
}

int			*ft_map_height(t_node **map)
{
	t_node *tmp;
	static int		*cmp;
	int		i;

	if (cmp)
		return (cmp);
	tmp = *map;
	cmp = malloc(sizeof(int) * 2);
	cmp[0] = 0;
	cmp[1] = -1;
	while (tmp)
	{
		i = 0;
		while (i < tmp->elem)
		{
			if (cmp[0] < tmp->tabz[i])
				cmp[0] = tmp->tabz[i];
			if (cmp[1] > tmp->tabz[i])
				cmp[1] = tmp->tabz[i];
			i++;
		}
		tmp = tmp->next;
	}
	return (cmp);
}
