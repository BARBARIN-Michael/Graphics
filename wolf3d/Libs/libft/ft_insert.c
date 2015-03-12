/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:10:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/09 13:40:30 by mbarbari         ###   ########.fr       */
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

void	ft_insert_tab2D(int **tab, char *elem, int nbr_elem, int line_insert)
{
	int		cmp;

	cmp = 0;
	while (cmp < nbr_elem)
	{
		tab[line_insert][cmp] = elem[cmp];
		cmp++;
	}
}
