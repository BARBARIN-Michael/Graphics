/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:57:02 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/02 11:36:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <unistd.h>

char		*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*rslt;

	rslt = s1;
	while (*s1)
		s1++;
	while (n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (rslt);
}

char		*ft_nstrncat(char *s1, char *s2, size_t ns1, size_t n)
{
	char	*rslt;

	ft_putendl2_c("ns1 vaux : ", ft_itoa(ns1), "green");
	ft_putendl2_c("test", " 2", "magenta");
	ft_putendl2_c("ns2 vaux : ", ft_itoa(n), "cyan");
	rslt = s1;
	while (ns1)
	{
		s1++;
		ns1--;
	}
	while (n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	ft_putendl_c(rslt, "red");
	return (rslt);
}
