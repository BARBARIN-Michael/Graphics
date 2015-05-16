/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 18:09:07 by agauci-d          #+#    #+#             */
/*   Updated: 2015/01/04 20:21:18 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute l'element new_elem en fin de liste.
*/

void ft_lstaddend(t_list **alst, t_list *new_elem)
{
	t_list	*cpy;

	if (!alst && !*alst)
	{
		ft_putendl("error ft_lstdaddend()");
		return ;
	}
	if (*alst == NULL)
		*alst = new_elem;
	else if (alst && new_elem)
	{
		cpy = *alst;
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = new_elem;
	}
}
