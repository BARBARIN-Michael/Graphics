/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:54:13 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/09 22:14:25 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str_dst;
	const unsigned char	*str_src;

	str_dst = dst;
	str_src = src;
	while (n--)
		*str_dst++ = *str_src++;
	return (dst);
}
