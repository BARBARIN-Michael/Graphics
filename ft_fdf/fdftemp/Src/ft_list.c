/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:47:44 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/18 18:28:56 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

t_node		*ft_new_lstfdf(t_node **map, int *tabz, char **col, int elem)
{
	t_node	*new_node;
	t_axe	new_axe;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
	{
		ft_del_map(map);
		ft_putendl_c("out of memory : Cannot read totaly file", "red");
		exit(1);
	}
	new_node->tabz = tabz;
	new_node->col = col;
	new_node->elem = elem;
	new_node->next = NULL;
	return (new_node);
}

t_node		*ft_lstadd_right(t_node **map, t_node *new)
{
	t_node		*temp_next;

	if (new)
	{
		if (!(*map))
		{
			*map = new;
			return (new);
		}
		temp_next = *map;
		while (temp_next->next != NULL)
			temp_next = temp_next->next;
		temp_next->next = new;
	}
	return (new);
}
