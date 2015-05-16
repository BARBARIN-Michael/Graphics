/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 10:22:53 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/16 13:47:10 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void array_clear(t_array *array)
{
	int i;

	i = 0; 
	if (array->elem_size > 0)
	{
		while (i < array->max)
		{
			if (array->contents[i] != NULL)
				free(array->contents[i]);
			i++;
		}
	}
}

void array_destroy(t_array *array)
{
	if (array) 
	{
		if (array->contents) 
			free(array->contents);
		free(array);
	}
}

void array_clear_destroy(t_array *array)
{
	array_clear(array);
	array_destroy(array);
}
