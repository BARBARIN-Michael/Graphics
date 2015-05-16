/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 16:37:14 by agauci-d          #+#    #+#             */
/*   Updated: 2015/03/19 14:53:26 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ulltoa(unsigned long long int arg)
{
	char						*dst;
	int							i;
	unsigned long long int		value;

	if (arg == 0)
		return ("0");
	i = ft_ull_len(arg) + 1;
	dst = (char *)malloc(sizeof(char) * (i));
	if (!dst)
		return (NULL);
	dst[i - 1] = '\0';
	i = i - 2;
	while (arg > 9)
	{
		value = arg % 10;
		dst[i] = value + '0';
		arg = (arg / 10);
		i--;
	}
	if (arg <= 9)
		dst[i] = arg + '0';
	return (dst);
}
