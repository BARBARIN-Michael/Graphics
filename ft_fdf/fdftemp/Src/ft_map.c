/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:12:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/12 15:57:29 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

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

int			*ft_map_height(t_node **map)
{
	t_node	*c_right;
	t_node	*c_left;
	int		*heightval;

	heightval = (int *)malloc(sizeof(int) * 2);
	c_right = *map;
	heightval[0] = 0;
	heightval[1] = -1;
	while (c_right)
	{
		c_left = c_right;
		while (c_left)
		{
			if (heightval[0] < c_left->xyz.z)
				heightval[0] = c_left->xyz.z;
			if (heightval[1] > c_left->xyz.z)
				heightval[1] = c_left->xyz.z;
			c_left = c_left->left_node;
		}
		c_right = c_right->right_node;
	}
	return (heightval);
}
