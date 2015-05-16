/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:30:03 by agauci-d          #+#    #+#             */
/*   Updated: 2014/11/11 11:30:57 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description:
** calcul la longueur de la chaine src jusqu'au caratere passe en parametre.
** param.
** #1 la chaine src.
** #2 le caractere d'arret.
** retour : la taille de src jusqu'au caractere c;
*/

size_t ft_strlentoc(const char *src, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src) + 1;
	while (src[i] != c && i < len)
		i++;
	return (i);
}
