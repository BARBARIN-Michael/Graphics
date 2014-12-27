/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:43:53 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:21:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*str;

	str = ft_memalloc(len + 1);
	if (!s1 || !str)
		return (NULL);
	ft_strncpy(str, s1 + start, len);
	str[len] = '\0';
	return (str);
}
