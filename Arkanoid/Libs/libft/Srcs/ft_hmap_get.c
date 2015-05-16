/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:30:39 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/24 12:05:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hmap.h>

int		hmap_get_node(t_hmap *map, t_uint hash, t_array *contents, void *key)
{
	int			i;
	t_hnode		*node;

	i = 0;
	while (i < ARRAY_END(contents))
	{
		node = array_get(contents, i);
		if (node->hash == hash && (map->compare(node->key, key) == 0))
			return (i);
		i++;
	}
	return (-1);
}

void	*hmap_get(t_hmap *map, void *key)
{
	t_uint	hash;
	t_hnode	*node;
	t_array	*contents;
	int		i;

	hash = 0;
	contents = hmap_find_contents(map, key, 0, &hash);
	if (!contents)
		return (NULL);
	i = hmap_get_node(map, hash, contents, key);
	if (i == -1)
		return (NULL);
	node = array_get(contents, i);
	CHECK(node != NULL, "Failed get node from contents when it should exist.");
	return (node->data);
}
