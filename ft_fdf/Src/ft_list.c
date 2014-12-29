/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:47:44 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/29 17:57:13 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

t_node		*ft_new_lstfdf(t_node *first, t_axe xyz)
{
	t_node	*new_node;
	t_axe	new_axe;

	if (!(new_node = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	new_axe.x = (double)x;
	new_axe.y = (double)y;
	new_axe.z = (double)z;
	node->xyz = new_axe;
	node->first_xnode = first;
	node->left_node = NULL;
	node->right_node = NULL;
}

void		ft_lstadd_backfdf(t_node **first, t_node *new, int cr)
{
	t_node		*temp_right;
	t_node		*temp_left;
	int			cmp;

	if (new)
	{
		if (!(*first))
		{
			*first = new;
			return ;
		}
		temp_right = *first;
		while (cmp++ <= cr)
			temp_right = temp_right->right_node;
		temp_left = temp_right;
		while (temp_left->left_node != NULL)
			temp_left = temp_left->left_node;
		temp_left->left_node = new;
		ft_update_prevnode(first, new, cr - 1);
	}
}

void		ft_update_prevnode(t_node **first, t_node *new, int cr)
{
	t_node		*tmp_right;
	t_node		*tmp_left;

	if (new)
	{
		tmp_right = *first;
		while (cr--)
			tmp_right = tmp_right->right_node;
		tmp_left = tmp_right;
		while (tmp_left->left_node != NULL)
			tmp_left = tmp_left->left_node;
		tmp_left->right_node = new;
	}
}

void		ft_print_map(t_node *map, int x, int y)
{
	t_node		*tmp_right;
	t_node		*tmp_left;
	int			xtemp;
	int			ytemp;

	tmp_right = map;
	xtemp = x;
	ytemp = y;
	while (ytemp--)
		tmp_right = tmp_right->right_node;
	tmp_left = tmp_right;
	while (xtemp--)
		tmp_left = tmp_left->left_node;
	ft_putendl_c("valeur de la valeur recherche :", "cyan");
	ft_putendl2_c("\t x -> ", ft_itoa(tmp_left->xyz.x), "red")
	ft_putendl2_c("\t y -> ", ft_itoa(tmp_left->xyz.y), "red")
	ft_putendl2_c("\t z -> ", ft_itoa(tmp_left->xyz.z), "red")
	ft_putendl_c("valeur de la valeur droite :", "cyan");
	ft_putendl2_c("\t x -> ", ft_itoa(tmp_left->right_node->xyz.x), "red")
	ft_putendl2_c("\t y -> ", ft_itoa(tmp_left->right_node->xyz.y), "red")
	ft_putendl2_c("\t z -> ", ft_itoa(tmp_left->right_node->xyz.z), "red")
	ft_putendl_c("valeur de la valeur gauche :", "cyan");
	ft_putendl2_c("\t x -> ", ft_itoa(tmp_left->left_node->xyz.x), "red")
	ft_putendl2_c("\t y -> ", ft_itoa(tmp_left->left_node->xyz.y), "red")
	ft_putendl2_c("\t z -> ", ft_itoa(tmp_left->left_node->xyz.z), "red")
}
