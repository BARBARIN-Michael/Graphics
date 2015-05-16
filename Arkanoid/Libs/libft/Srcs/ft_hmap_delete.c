/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:17:41 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/24 13:48:29 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hmap.h>

void	hmap_destroy(t_hmap *map)
{
	int			i;
	int			j;
	t_array		*contents;

	i = 0;
	j = 0;
	if (map)
	{
		if (map->contents)
		{
			while (i < ARRAY_COUNT(map->contents))
			{
				contents = array_get(map->contents, i);
				if (contents)
				{
					while (j < ARRAY_COUNT(contents))
						free(array_get(contents, j));
					array_destroy(contents);
				}
			}
			array_destroy(map->contents);
		}
		free(map);
	}
}

void	*hmap_delete(t_hmap *map, void *key)
{
	t_uint		hash;
	void		*data;
	t_array		*contents;
	int			i;
	t_node_h	nh;

	contents = hmap_find_contents(map, key, 0, &hash);
	hash = 0;
	if (!contents)
		return (NULL);
	if ((i = hmap_get_node(map, hash, contents, key)) == -1)
		return (NULL);
	nh.node = array_get(contents, i);
	data = nh.node->data;
	free(nh.node);
	nh.ending = array_pop(contents);
	if (nh.ending != nh.node)
		array_set(contents, i, nh.ending);
	return (data);
}
