/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:47:09 by agauci-d          #+#    #+#             */
/*   Updated: 2014/12/30 15:04:14 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isint(int n)
{
	int		sign;
	char	*nbr;

	sign = 1;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	nbr = ft_itoa(n);
	if (nbr[0] > '2' && nbr[1] > '1' && nbr[2] > '4' && nbr[3] > '7' &&
			nbr[4] > '4' && nbr[5] > '8' && nbr[6] > '3' && nbr[7] > '6'
			&& nbr[8] > '4')
		return (0);
	if (nbr[9] > '8')
	{
		if (nbr[9] > 7 && sign == 1)
			return (0);
		return (0);
	}
	return (1);
}

static int		ft_intleng(int n)
{
	int i;

	i = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (i > 11)
		return (0);
	if (i == 11)
		return (ft_isint(n));
	return (i);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (ft_intleng(n) == 0)
		return ;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n <= 9)
		ft_putchar_fd((n + '0'), fd);
}
