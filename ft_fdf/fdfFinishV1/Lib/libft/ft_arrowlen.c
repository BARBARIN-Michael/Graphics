/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrowlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 14:35:24 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/13 03:56:52 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		*ft_lengthtab(char **line)
{
	static int	lengthtab[2];
	int			width;
	char		**linesave;

	linesave = line;
	lengthtab[0] = 0;
	lengthtab[1] = 0;
	while (*linesave != NULL)
	{
		width = 0;
		while (**linesave != '\0')
		{
			width++;
			**linesave++;
		}
		if (width > lengthtab[0])
			lengthtab[0] = width;
		lengthtab[1]++;
		*linesave++;
	}
	return (lengthtab);
}

int		ft_lengthtabn(char *line, int c)
{
	int		i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c && line[i - 1] != c)
			cmp++;
	}
	return (cmp);
}
