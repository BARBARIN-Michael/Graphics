/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:00:05 by mbarbari          #+#    #+#             */
/*   Updated: 2014/11/23 17:21:48 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	(*del)((*alst)->content, (*alst)->content_size);
	lst = (*alst)->next;
	while (lst)
	{
		(*del)(lst->content, lst->content_size);
		lst = lst->next;
	}
	ft_memdel((void **)alst);
}
