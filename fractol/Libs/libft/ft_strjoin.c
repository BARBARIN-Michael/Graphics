/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:07:09 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/05 17:25:01 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 && s2)
		return (ft_strdup(s1));
	if (!s2 && s1)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_strnew(len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	if (!ft_strcat(str, s1))
		return (NULL);
	if (!ft_strcat(str, (char *)s2))
		return (NULL);
	return (str);
}

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	int		len_s1;

	if (!s1 && s2)
		return (ft_strdup(s1));
	if (!s2 && s1)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	str = ft_strnew(len_s1 + n + 1);
	if (!str)
		return (NULL);
	if (!ft_strcat(str, s1))
		return (NULL);
	if (!ft_strncat(str, (char *)s2, n))
		return (NULL);
	return (str);
}
