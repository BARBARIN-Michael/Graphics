/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:23:51 by agauci-d          #+#    #+#             */
/*   Updated: 2015/04/14 14:14:17 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Alloue (avec malloc(3)) et retourne une chaine de caracteres fraiche
** terminee par un '\0' resultant de la concatenation de s1 et s2. Si
** l'allocation echoue, la fonction renvoie NULL.
** Si s1 est null, s2 est renvoye. Si s2 est null, s1 est renvoye.
*/

char *ft_strjoin_null(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2 && s1)
		return ((char *)s1);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	if (!s1 && s2)
		return ((dst = (char *)s2));
	else if (!s1 && !s2)
		return (NULL);
	while (s1[i++] != '\0')
		dst[i] = s1[i];
	while (s2[j] != '\0')
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
