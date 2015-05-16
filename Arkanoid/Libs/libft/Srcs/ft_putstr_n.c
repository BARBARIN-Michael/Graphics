/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:53:38 by agauci-d          #+#    #+#             */
/*   Updated: 2015/03/09 20:54:47 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void ft_putstr_n(char *s, int start, int len)
{
	int j;

	j = 0;
	if (!s)
		return ;
	while (s[start] && j < len)
	{
		ft_putchar(s[start]);
		start++;
		j++;
	}
}
