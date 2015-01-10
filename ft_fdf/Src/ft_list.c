/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:47:44 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/10 12:24:12 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

t_node		*ft_new_lstfdf(t_node *first, t_axe xyz, char *col)
{
	t_node	*new_node;
	t_axe	new_axe;

	if (!(new_node = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	new_axe.x = xyz.x;
	new_axe.y = xyz.y;
	new_axe.z = xyz.z;
	new_node->col = col;
	new_node->xyz = new_axe;
	new_node->first_xnode = first;
	new_node->left_node = NULL;
	new_node->right_node = NULL;
	return (new_node);
}

t_node		*ft_lstadd_right(t_node **map, t_node *new)
{
	t_node		*temp_right;

	if (new)
	{
		if (!(*map))
		{
			*map = new;
			new->first_xnode = new;
			return (new);
		}
		temp_right = *map;
		while (temp_right->right_node != NULL)
			temp_right = temp_right->right_node;
		temp_right->right_node = new;
		new->first_xnode = new;
	}
	return (new);
}

void		ft_lstadd_left(t_node **line, t_node **prev, t_node *new)
{
	t_node		*tmp_prev;
	t_node		*tmp_line;

	tmp_line = *line;
	tmp_prev = NULL;
	if (*prev != NULL)
		tmp_prev = *prev;
	if (new)
	{
		while (tmp_line->left_node != NULL)
		{
			if (tmp_prev != NULL && tmp_prev->left_node != NULL)
				tmp_prev = tmp_prev->left_node;
			tmp_line = tmp_line->left_node;
		}
		if (tmp_prev != NULL)
			tmp_prev->left_node->right_node = new;
		tmp_line->left_node = new;
		new->first_xnode = tmp_line->first_xnode;
	}
}

void		ft_del_map(t_node **map)
{
	t_node *tmp_right;
	t_node *tmp_left;
	t_node *tmpr;
	t_node *tmpl;

	tmp_right = *map;
	tmp_left = NULL;
	while (tmp_right != NULL)
	{
		tmpr = tmp_right->right_node;
		tmp_left = tmp_right;
		while (tmp_left != NULL)
		{
			tmpl = tmp_left->left_node;
			if (tmp_left)
			{
				free(tmp_left->col);
				free(tmp_left);
			}
			tmp_left = tmpl;
		}
		tmp_right = tmpr;
	}
}

void modifier_data_lst(t_node **map, int z)
{
	t_node *c_right;
	t_node *c_left;

	c_right = *map;
	while (c_right)
	{
		c_left = c_right;
		while (c_left)
		{
				c_left->xyz.z *= z;
			c_left = c_left->left_node;
		}
		c_right = c_right->right_node;
	}
}
