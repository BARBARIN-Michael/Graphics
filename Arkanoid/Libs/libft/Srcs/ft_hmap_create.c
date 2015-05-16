/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 17:24:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/24 15:43:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hmap.h>

static int		default_compare(void *a, void *b)
{
	int cmp;

	cmp = ft_strcmp((char *)a, (char *)b);
	return (cmp);
}

static t_uint	default_hash(void *a)
{
	size_t		len;
	char		*key;
	t_uint		hash;
	t_uint		i;

	len = ft_strlen((char *)a);
	key = (char *)a;
	hash = 0;
	i = 0;
	while (i < len)
	{
		hash += key[i++];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

t_hmap			*hmap_create(hmap_compare compare, hmap_hash hash)
{
	t_hmap *map;

	if (!(map = ft_memalloc(sizeof(t_hmap))))
		return (ft_printf("Out of memory (hmap_create map)!"), NULL);
	map->compare = compare == NULL ? default_compare : compare;
	map->hash = hash == NULL ? default_hash : hash;
	if (!(map->contents = array_create(sizeof(t_array *), DEFAULT_NB_CONTENTS)))
		return (ft_printf("Out of memory (hmap_create contents)!"), NULL);
	map->contents->end = map->contents->max;
	return (map);
}

t_hnode			*hmap_node_create(int hash, void *key, void *data)
{
	t_hnode *node;

	if (!(node = ft_memalloc(sizeof(t_hnode))))
		return (ft_printf("Out of memory (hnode_create node)!"), NULL);
	node->key = key;
	node->data = data;
	node->hash = hash;
	return (node);
}

int				hmap_set(t_hmap *map, void *key, void *data)
{
	t_uint		hash;
	t_array		*contents;
	t_hnode		*node;

	hash = 0;
	if (!(contents = hmap_find_contents(map, key, 1, &hash)))
		return (ft_printf("Error can't create contents."), -1);
	if (!(node = hmap_node_create(hash, key, data)))
		return (ft_printf("Out of memory (hmap_set node)!"), -1);
	array_push(contents, node);
	return (0);
}
