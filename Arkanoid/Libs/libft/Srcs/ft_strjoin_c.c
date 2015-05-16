/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 11:24:59 by agauci-d          #+#    #+#             */
/*   Updated: 2015/03/09 20:55:13 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strjoin_c(char c)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * 2);
	if (!dst)
		return (NULL);
	dst[0] = c;
	dst[1] = '\0';
	return (dst);
}
