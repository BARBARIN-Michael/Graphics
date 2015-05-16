/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:35:18 by mbarbari          #+#    #+#             */
/*   Updated: 2015/04/16 18:56:28 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

void	ft_strndel(int n, ...)
{
	va_list ap;

	va_start(ap, n);
	while (n)
	{
		ft_memdel((void **)va_arg(ap, void **));
		n--;
	}
	va_end(ap);
}
