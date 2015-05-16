/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 10:20:49 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/16 12:01:10 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H
# include <libft.h>

#define DEFAULT_EXPAND_RATE 300

# define ARRAY_LAST(A) ((A)->contents[(A)->end - 1])
# define ARRAY_FIRST(A) ((A)->contents[0])
# define ARRAY_END(A) ((A)->end)
# define ARRAY_COUNT(A) ARRAY_END(A)
# define ARRAY_MAX(A) ((A)->max)

typedef struct	s_array
{
	int		end;
	int		max;
	size_t	elem_size;
	size_t	expand_rate;
	void	**contents;
}				t_array;

t_array		*array_create(size_t elem_size, size_t initial_max);
void		array_destroy(t_array *array);
void		array_clear(t_array *array);
int			array_expand(t_array *array);
int			array_contract(t_array *array);
int			array_push(t_array *array, void *el);
void		*array_pop(t_array *array);
void		array_clear_destroy(t_array *array);

void		array_set(t_array *array, int i, void *el);
void		*array_get(t_array *array, int i);
void		*array_remove(t_array *array, int i);
void		*array_new(t_array *array);
int			array_resize(t_array *array, size_t newsize);

# define ARRAY_FREE(E) free((E))

#endif

