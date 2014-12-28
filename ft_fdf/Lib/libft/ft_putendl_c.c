/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:24:17 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/28 10:52:40 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* *************************************************
** # define C_BLACK        "\033[30m"
** # define C_RED          "\033[31m"
** # define C_GREEN        "\033[32m"
** # define C_BROWN        "\033[33m"
** # define C_BLUE         "\033[34m"
** # define C_MAGENTA      "\033[35m"
** # define C_CYAN         "\033[36m"
** # define C_GRAY         "\033[37m"
** ***************************************************/

static int	putcolor(char *color)
{
	if (ft_strcmp(color, "red") == 0 || ft_strcmp(color, "RED") == 0)
		return (31);
	else if (ft_strcmp(color, "green") == 0 || ft_strcmp(color, "GREEN") == 0)
		return (32);
	else if (ft_strcmp(color, "brown") == 0 || ft_strcmp(color, "BROWN") == 0)
		return (33);
	else if (ft_strcmp(color, "blue") == 0 || ft_strcmp(color, "BLUE") == 0)
		return (34);
	else if (ft_strcmp(color, "magenta") == 0
				|| ft_strcmp(color, "MAGENTA") == 0)
		return (35);
	else if (ft_strcmp(color, "cyan") == 0 || ft_strcmp(color, "CYAN") == 0)
		return (36);
	else 
		return (0);
}

void	ft_putendl_c(char const *s, char *color)
{
	char *palet_color;

	palet_color = ft_strjoin("\033[%sm", s);
	palet_color = ft_replace(palet_color, "%s", ft_itoa(putcolor(color)));
	ft_putendl(palet_color);
	ft_putstr(C_NONE);
	ft_strdel(&palet_color);
}

void	ft_putendl2_c(char const *s1, char const *s2, char *color)
{
	char *palet_color;

	palet_color = ft_strjoin("\033[%sm", s1);
	palet_color = ft_replace(palet_color, "%s", ft_itoa(putcolor(color)));
	ft_putstr(palet_color);
	ft_putendl(s2);
	ft_strdel(&palet_color);
	ft_putstr(C_NONE);
}
