/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:10:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/16 12:32:37 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_insert(char *str, int elem, char *val)
{
	char *rslt;

	rslt = str;
	while (elem)
	{
		*str++ = *val++;
		elem--;
	}
	return (rslt);
}
