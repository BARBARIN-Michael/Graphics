/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:47:43 by agauci-d          #+#    #+#             */
/*   Updated: 2015/03/10 16:33:55 by agauci-d         ###   ########.fr       */
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
	int flag;
	int save;

	i = 1;
	flag = 1;
	save = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -1 * n;
		flag = -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if (i > 11)
		return (0);
	if (i == 11)
		return (ft_isint(save * flag));
	return (i);
}

void			ft_putnbr_dl(int n)
{
	if (n == -2147483648)
	{
		ft_putendl("-2147483648");
		return ;
	}
	if (ft_intleng(n) == 0)
		return ;
	if (n == 0)
	{
		ft_putendl("0");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	ft_putchar('\n');
}
