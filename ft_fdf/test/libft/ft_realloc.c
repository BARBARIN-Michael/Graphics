/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 19:26:38 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/23 10:15:48 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *src, size_t len)
{
	void	*str;

	if (!src)
	{
		src = (void *)ft_memalloc(sizeof(src) * (len + 1));
		if (!src)
			return (NULL);
		return (src);
	}
	else
	{
		str = (char *)ft_memalloc(sizeof(src) * (ft_strlen(src) + len));
		if (!str)
			return (NULL);
		else
			ft_memcpy(str, src, ft_strlen(src));
		ft_memdel(&src);
	}
	return (str);
}
