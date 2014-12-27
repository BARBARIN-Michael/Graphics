/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_deb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 01:01:53 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 01:11:40 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fnctl.h>
#include "libft.h"

void		*ft_memalloc_deb(size_t size)
{
	void	*tmp;
	void	*ptrd;

	tmp = malloc(size);
	if (tmp == NULL)
		return (NULL);
	else
	{
		ft_bzero(tmp, size);
		ptrd = tmp;
		ft_debug_ptr(&ptrd, &(ptrd + size));
		return (tmp);
	}
}
