/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:13:28 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 03:58:27 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nbr, int fd)
{
	char	rslt;

	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write (fd, "-", 1);
		nbr = -nbr;
	}
	rslt = '0' + (nbr % 10);
	if (nbr / 10 != 0)
		ft_putnbr_fd(nbr / 10, fd);
	write(fd, &rslt, 1);
}
