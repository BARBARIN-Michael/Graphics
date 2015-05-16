/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 12:09:27 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/16 11:39:56 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_CHECKing.h>
#include <ft_array.h>
#include <libft.h>
#include <ft_printf.h>

t_array		*array_create(size_t elem_size, size_t initial_max)
{
	t_array *array;

	array = ft_memalloc(sizeof(t_array));
	CHECK(array, "array_create - Out of Memory!");
	array->max = initial_max;
	CHECK(array->max > 0, "You must set an initial_max > 0.");
	array->contents = ft_memalloc(initial_max * sizeof(void *));
	CHECK(array->contents, "array_create - Out of Memory!");
	array->end = 0;
	array->elem_size = elem_size;
	array->expand_rate = DEFAULT_EXPAND_RATE;
	return (array);
}

int			array_expand(t_array *array)
{
	size_t old_max;
	
	old_max = array->max;
	CHECK(array_resize(array, array->max + array->expand_rate) == 0,
			"Failed to expand array to new size: %d",
			array->max + (int)array->expand_rate);

	ft_memset(array->contents + old_max, 0, array->expand_rate + 1);
	return (0);
}

int			array_contract(t_array *array)
{
	int		new_size;
	
	if (array->end < (int)array->expand_rate)
		new_size = (int)array->expand_rate;
	else
		new_size = array->end;
	return (array_resize(array, new_size + 1));
}

void		*array_pop(t_array *array)
{
	void	*el;

	CHECK(array->end - 1 >= 0, "Attempt to pop from empty array.");
	el = array_remove(array, array->end - 1);
	array->end--;
	if (ARRAY_END(array) > (int)array->expand_rate 
			&& ARRAY_END(array) % array->expand_rate)
		array_contract(array);
	return (el);
}

int			array_push(t_array *array, void *el)
{
	array->contents[array->end] = el;
	array->end++;
	if (ARRAY_END(array) >= ARRAY_MAX(array))
		return (array_expand(array));
	else 
		return (0);
}
