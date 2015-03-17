/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 06:04:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/17 13:36:18 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static int		read_file(int fd, char **str)
{
	char	*buf;
	int		rslt;

	rslt = 1;
	buf = NULL;
	while (rslt > 0)
	{
		if (!buf)
			buf = malloc(BUFF_SIZE + 1);
		if ((rslt = read(fd, buf, BUFF_SIZE)) <= 0)
		{
			ft_strdel(&buf);
			return (rslt);
		}
		buf[rslt] = '\0';
		*str = (char *)ft_realloc(*str, rslt);
		*str = ft_strcat(*str, buf);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	ft_strdel(&buf);
	return (rslt);
}

static int		is_dispatch(char **str, char **line)
{
	char		*trf;
	char		*tmp;

	trf = NULL;
	if (*str == '\0')
		return (0);
	else if ((tmp = ft_strchr(*str, '\n')) != NULL)
	{
		trf = ft_strsub(*str, 0, tmp - *str);
		*str = tmp + 1;
		ft_strdel(line);
		*line = ft_strdup(trf);
		ft_strdel(&trf);
		return (1);
	}
	return (0);
}

static int		after_init(t_vargnl **v, char **line, int fd)
{
	if ((is_dispatch(&(*v)->s1, line)) == 1)
		return (1);
	if (!ft_findchr((*v)->s1, '\n'))
	{
		ft_bzero((*v)->s2, (*v)->s1 - (*v)->s2);
		if ((*v)->s1 != (*v)->s2)
			ft_memmove((*v)->s2, (*v)->s1, ft_strlen((*v)->s1));
		ft_bzero((*v)->s1, ft_strlen((*v)->s1));
		(*v)->s1 = (*v)->s2;
		if (((*v)->rslt = read_file(fd, &(*v)->s1)) <= 0)
		{
			if ((*v)->rslt == 0 && (*v)->s1 && (*(*v)->s1 != ('\n' && '\0')))
			{
				ft_strdel(line);
				*line = ft_strdup((*v)->s1);
				ft_strdel(&(*v)->s1);
				return (1);
			}
			ft_strdel(&(*v)->s1);
			return ((*v)->rslt);
		}
		(*v)->s2 = (*v)->s1;
		is_dispatch(&(*v)->s1, line);
	}
	return (1);
}

static t_vargnl	*lstfind_byfd(t_list **lst, int fd)
{
	t_list		*lsttmp;
	t_vargnl	*var;

	if (lst)
		lsttmp = *lst;
	else
		lsttmp = NULL;
	while (lsttmp)
	{
		var = lsttmp->content;
		if (var->fd == fd)
			return (var);
		lsttmp = lsttmp->next;
	}
	var = (t_vargnl *)malloc(sizeof(t_vargnl));
	var->s1 = NULL;
	var->fd = fd;
	lsttmp = ft_lstnew(var, sizeof(t_vargnl));
	var = lsttmp->content;
	ft_lstadd(lst, lsttmp);
	return (var);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst = NULL;
	t_vargnl			*var;

	if (!line || fd < 0)
		return (-1);
	var = lstfind_byfd(&lst, fd);
	if (!var->s1)
	{
		if ((var->rslt = read_file(fd, &var->s1)) <= 0)
		{
			if (var->rslt == 0 && var->s1 && *var->s1 != ('\n' && '\0'))
			{
				ft_strdel(line);
				*line = ft_strdup(var->s1);
				ft_strdel(&var->s1);
				return (1);
			}
			return (var->rslt);
		}
		var->s2 = var->s1;
	}
	return (after_init(&var, line, fd));
}
