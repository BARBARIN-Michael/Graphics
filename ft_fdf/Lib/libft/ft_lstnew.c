/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:09:30 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/14 14:28:12 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*l_assign(t_list *lst, void const *content, size_t content_size)
{
	lst->content = ft_memcpy(lst->content, content, content_size);
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst_new;

	if (!(lst_new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(lst_new->content = ft_memalloc(content_size)))
		{
			ft_memdel(&lst_new->content);
			return (NULL);
		}
		return (l_assign(lst_new, content, content_size));
	}
	else
		return (l_assign(lst_new, NULL, 0));
}
