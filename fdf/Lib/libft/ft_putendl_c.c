/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:24:17 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/06 19:12:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_c(char const *s, int color)
{
	char *palet_color;

	palet_color = ft_strjoin("\033[3%sm", s);
	palet_color = ft_replace(palet_color, "%s", ft_itoa(color));
	ft_putendl(palet_color);	
	ft_putstr(C_NONE);
}
