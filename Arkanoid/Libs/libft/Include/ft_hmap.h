/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 11:21:31 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/24 12:09:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_H
# define FT_HMAP_H

# include <ft_array.h>
# include <libft.h>
# include <ft_checking.h>

# define DEFAULT_NB_CONTENTS	100

typedef int		(*hmap_compare)(void *a, void *b);
typedef t_uint	(*hmap_hash)(void *key);

typedef struct	s_hmap
{
	t_array			*contents;
	hmap_compare	compare;
	hmap_hash		hash;
}				t_hmap;

typedef struct	s_hmap_node
{
	void	*key;
	void	*data;
	t_uint	hash;
}				t_hnode;

typedef struct	s_node_h
{
	t_hnode *ending;
	t_hnode	*node;
}				t_node_h;

typedef int (*hmap_parse)(t_hnode *node);
t_hmap		*hmap_create(hmap_compare compare, hmap_hash hash);
void		hmap_destroy(t_hmap *map);
int			hmap_set(t_hmap *map, void *key, void *data);
void		*hmap_get(t_hmap *map, void *key);
int			hmap_next(t_hmap *map, hmap_parse next);
void		*hmap_delete(t_hmap *map, void *key);

t_hnode		*hmap_node_create(int hash, void *key, void *data);
int			hmap_get_node(t_hmap *map, t_uint hash, t_array *cont, void *key);
t_array		*hmap_find_contents(t_hmap *map, void *key,
												int create, t_uint *hash_out);

#endif
