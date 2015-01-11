/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 10:16:51 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/11 13:58:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *src, char const *join)
{
	char		*str;

	if (!src || !join)
		return (NULL);
	str = (char *)ft_memalloc(sizeof(src) * (ft_strlen(src) + ft_strlen(join)) + 1);
	if (!str)
		return (NULL);
	else
		ft_strncpy(str, src, ft_strlen(src));
		ft_strdel(&src);
	ft_strcat(str, join);
	return (str);
}
