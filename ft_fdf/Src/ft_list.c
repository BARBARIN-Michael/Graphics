/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:47:44 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/31 08:08:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

t_node		*ft_new_lstfdf(t_node *first, t_axe xyz)
{
	t_node	*new_node;
	t_axe	new_axe;

	if (!(new_node = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	new_axe.x = xyz.x;
	new_axe.y = xyz.y;
	new_axe.z = xyz.z;
	new_node->xyz = new_axe;
	new_node->first_xnode = first;
	new_node->left_node = NULL;
	new_node->right_node = NULL;
	return (new_node);
}

t_node		*ft_lstadd_right(t_node **map, t_node *new)
{
	t_node		*temp_right;
	int			cmp;

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
	int			cmp;

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
	t_node *tmp;

	tmp_right = *map;
	while (!(tmp_right))
	{
		tmp_left = tmp_right;
		while (!(tmp_left))
		{
			tmp = tmp_left->left_node;
			free(tmp_left);
			tmp_left = tmp;
		}
		tmp = tmp_right->right_node;
		free(tmp_right);
		tmp_right = tmp;
	}
}

//A supprimer
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
	ft_putstr_c("valeur de la valeur recherche :", "cyan");
	printf(C_GREEN"  %p\n"C_NONE, tmp_left);
	ft_putstr_c("valeur de la list primaire :", "cyan");
	printf(C_GREEN"  %p\n"C_NONE, tmp_left->first_xnode);
	printf(C_RED"\t x -> %f\n"C_NONE, tmp_left->xyz.x);
	printf(C_RED"\t y -> %f\n"C_NONE, tmp_left->xyz.y);
	printf(C_RED"\t z -> %f\n"C_NONE, tmp_left->xyz.z);
	if (tmp_left->left_node)
	{
		ft_putstr_c("valeur de la valeur gauche :", "brown");
		printf(C_GREEN"  %p\n"C_NONE, tmp_left->left_node);
	ft_putstr_c("valeur de la list primaire :", "cyan");
	printf(C_GREEN"  %p\n"C_NONE, tmp_left->left_node->first_xnode);
		printf(C_RED"\t x -> %f\n"C_NONE, tmp_left->left_node->xyz.x);
		printf(C_RED"\t y -> %f\n"C_NONE, tmp_left->left_node->xyz.y);
		printf(C_RED"\t z -> %f\n"C_NONE, tmp_left->left_node->xyz.z);
	}
	if (tmp_left->right_node)
	{
		ft_putstr_c("valeur de la valeur droite :", "brown");
		printf(C_GREEN"  %p\n"C_NONE, tmp_left->right_node);
	ft_putstr_c("valeur de la list primaire :", "cyan");
	printf(C_GREEN"  %p\n"C_NONE, tmp_left->right_node->first_xnode);
		printf(C_RED"\t x -> %f\n"C_NONE, tmp_left->right_node->xyz.x);
		printf(C_RED"\t y -> %f\n"C_NONE, tmp_left->right_node->xyz.y);
		printf(C_RED"\t z -> %f\n"C_NONE, tmp_left->right_node->xyz.z);
	}
}
