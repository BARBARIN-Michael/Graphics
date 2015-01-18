/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:12:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 19:43:53 by mbarbari         ###   ########.fr       */
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
	map = map;
	return (NULL);
}
