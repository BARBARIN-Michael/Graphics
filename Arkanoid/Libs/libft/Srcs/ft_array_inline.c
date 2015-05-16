/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_inline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 10:51:53 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/16 13:53:17 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_array.h>
#include <ft_checking.h>

void array_set(t_array *array, int i, void *el)
{
	CHECK(i < array->max, "array attempt to set past max");
	if(i > array->end)
		array->end = i;
	array->contents[i] = el;
	return ;
}

void *array_get(t_array *array, int i)
{
	CHECK(i < array->max, "array attempt to get past max");
	return (array->contents[i]);
}

void *array_remove(t_array *array, int i)
{
	void *el;

	el = array->contents[i];
	array->contents[i] = NULL;
	return (el);
}

void *array_new(t_array *array)
{
	CHECK(array->elem_size > 0, "Can't use array_new on 0 size arrays.");
	return (ft_memalloc(array->elem_size));
}

int array_resize(t_array *array, size_t newsize)
{
	void *contents;

	array->max = newsize;
	CHECK(array->max > 0, "The newsize must be > 0.");
	contents = ft_realloc((char *)array->contents, array->max * sizeof(void *));
	CHECK(contents, "Out of memory : function array_resize");
	array->contents = contents;
	return (0);
}
