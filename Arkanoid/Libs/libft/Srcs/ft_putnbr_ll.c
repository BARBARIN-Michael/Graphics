/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:05:45 by agauci-d          #+#    #+#             */
/*   Updated: 2015/03/09 20:53:22 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void			ft_putnbr_ll(long long int n)
{
	if (n > LLONG_MAX || n < LLONG_MIN)
		return ;
	if (n == LLONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
}
