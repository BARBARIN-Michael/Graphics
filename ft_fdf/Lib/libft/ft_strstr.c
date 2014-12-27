/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:49:44 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:21:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		len_s2;

	len_s2 = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		if (ft_strncmp(s1, s2, len_s2) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
