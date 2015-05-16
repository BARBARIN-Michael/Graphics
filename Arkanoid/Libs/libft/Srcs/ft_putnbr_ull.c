/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:05:45 by agauci-d          #+#    #+#             */
/*   Updated: 2015/03/09 20:53:48 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_ull(unsigned long long int n)
{
	if (n > ULLONG_MAX)
		return ;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n >= 10)
	{
		ft_putnbr_ull(n / 10);
		ft_putnbr_ull(n % 10);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
}
