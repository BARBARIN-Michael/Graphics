/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 09:39:53 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/27 16:35:20 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

int		ft_coord_nbr(char *str)
{
	int		cmp;
	int		i;

	cmp = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && (str[i - 1] != ' ' && i > 1))
			cmp++;
		i++;
	}
	cmp++;
	return (cmp);
}

t_list			*ft_parsefile(char *file)
{
	t_list		*tab = NULL;
	int			fd;
	int			rslt;
	char		*str;

	str = NULL;
	fd = open(file, O_RDONLY);
	while ((rslt = get_next_line(fd, &str)) > 0)
	{
		str = ft_strjoin_free(str, " ");
		ft_lstadd_back(&tab, ft_lstnew(ft_strdup(str), ft_strlen(str) + 1));
		ft_strdel(&str);
	}
	close(fd);
	if (rslt < 0)
	{
		ft_putendl(C_RED"ERROR x104 : Cannot open file");
		exit(1);
	}
	return (tab);
}

unsigned int			ft_getvalue(char *str, int x)
{
	char	*tmp;
	int		cmp;
	int		nbr;

	tmp = str;
	cmp = 0;
	while (*tmp != '\0' && cmp != x)
	{
		if (*tmp == ' ')
			cmp++;
		tmp++;
	}
	if (*tmp == '\0')
		return (-1);
	nbr = (unsigned int)ft_atoi(ft_strsub(tmp, 0, ft_strchr(tmp, ' ') - tmp));
	return (nbr);
}
