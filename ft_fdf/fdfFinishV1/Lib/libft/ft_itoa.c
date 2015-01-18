/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:02:24 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/28 11:00:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		is_sign(int nbr)
{
	if (nbr < 0)
		return (1);
	else
		return (0);
}

static int		nbr_digit(int nbr)
{
	int		cmp_digit;

	cmp_digit = 0;
	if (nbr < 0)
	{
		cmp_digit++;
		nbr = -nbr;
	}
	else if (nbr == 0)
		cmp_digit = 1;
	while ((nbr) != 0)
	{
		cmp_digit++;
		nbr /= 10;
	}
	return (cmp_digit);
}

static char		*is_limite(int nbr)
{
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (nbr == 2147483647)
		return (ft_strdup("2147483647"));
	else if (nbr == 0)
		return (ft_strdup("0"));
	else
		return (NULL);
}

char			*ft_itoa(int nbr)
{
	char	*str;
	int		cmp;
	int		sign;

	cmp = nbr_digit(nbr);
	str = ft_strnew(cmp);
	sign = 0;
	if (is_limite(nbr) != NULL)
		return (is_limite(nbr));
	sign = is_sign(nbr);
	if (sign == 1)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[cmp] = '\0';
	while (nbr)
	{
		str[cmp - 1] = '0' + (nbr % 10);
		nbr /= 10;
		cmp--;
	}
	return (str);
}
