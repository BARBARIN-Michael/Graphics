/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 19:22:50 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/02 11:52:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hmap.h>

int			hmap_next(t_hmap *map, hmap_parse parse)
{
	int		i;
	int		j;
	int		rc;
	t_array	*contents;
	t_hnode	*node;

	i = 0;
	j = 0;
	rc = 0;
	while (i < ARRAY_COUNT(map->contents))
	{
		contents = array_get(map->contents, i);
		if (contents)
		{
			while (j < ARRAY_COUNT(contents))
			{
				node = array_get(contents, j);
				rc = parse(node);
				if (rc != 0)
					return (rc);
			}
		}
	}
	return (0);
}

t_array		*hmap_find_contents(t_hmap *map, void *key,
		int create, t_uint *hash_out)
{
	t_uint	hash;
	int		contents_n;
	t_array	*contents;

	hash = map->hash(key);
	contents_n = hash % DEFAULT_NB_CONTENTS;
	CHECK(contents_n >= 0, "Invalid contents found: %d", contents_n);
	*hash_out = hash;
	contents = array_get(map->contents, contents_n);
	if (!contents && create)
	{
		contents = array_create(sizeof(void *), DEFAULT_NB_CONTENTS);
		CHECK(contents, "Out of Memory (hmap_find contents)!");
		array_set(map->contents, contents_n, contents);
	}
	return (contents);
}
