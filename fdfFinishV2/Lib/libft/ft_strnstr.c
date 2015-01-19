/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:42:19 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:21:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char		val_s2;
	char		val_s1;
	size_t		len;
	int			cmp;

	cmp = 0;
	if ((val_s2 = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!cmp || ft_strncmp(s1, s2, len) != 0)
		{
			cmp = 1;
			if ((val_s1 = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (val_s1 != val_s2)
			{
				if ((val_s1 = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
