/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:22:17 by agauci-d          #+#    #+#             */
/*   Updated: 2015/03/19 15:53:23 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int ft_atoll(char *str)
{
	int					sign;
	long long int		number;
	long long int		figure;
	int					i;

	sign = 0;
	number = 0;
	figure = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit (str[i]) && str[i] != '\0')
	{
		figure = (long long int)(str[i] - '0');
		number = (number * 10) + figure;
		i++;
	}
	return (number * sign);
}
