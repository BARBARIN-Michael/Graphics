/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 09:39:53 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/04 23:55:59 by mbarbari         ###   ########.fr       */
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
		if (str[i] == ' ' && i > 0 && str[i - 1] != ' ' && str[i + 1] != '\0')
			cmp++;
		i++;
	}
	cmp++;
	return (cmp);
}

t_node			*ft_parsefile(char *file)
{
	t_node		*map = NULL;
	int			fd;
	int			rslt;
	char		*str;
	int			y;

	str = NULL;
	y = 1;
	fd = open(file, O_RDONLY);
	while ((rslt = get_next_line(fd, &str)) > 0)
	{
		ft_insert_map(str, &map, y);
		ft_strdel(&str);
		y++;
	}
	close(fd);
	if (rslt < 0)
	{
		ft_putendl(C_RED"ERROR x104 : Cannot open file"C_NONE);
		exit(1);
	}
	return (map);
}

unsigned int			ft_getvalue(char *str, int x)
{
	static char	**tmp;
	int			nbr;

	if (tmp == NULL)
		tmp = ft_strsplit(str, ' ');
	nbr = ft_atoi(tmp[x]);
	free(tmp[x]);
	tmp[x] = NULL;
	if (tmp[x + 1] == NULL)
	{
		free(tmp);
		tmp = NULL;
	}
	return (nbr);
}

void					ft_insert_map(char *str, t_node **map, int y)
{
	static t_node	*prev = NULL;
	t_node			*line_node;
	int				x;
	int				tablen;
	t_axe			xyz;

	x = 0;
	line_node = NULL;
	tablen = ft_coord_nbr(str);
	while (x < tablen)
	{
		xyz.x = x + 1;
		xyz.y = y;
		xyz.z = ft_getvalue(str, x);
		if (!line_node)
			line_node = ft_lstadd_right(map,ft_new_lstfdf(NULL, xyz));
		else
			ft_lstadd_left(&line_node, &prev, ft_new_lstfdf(NULL, xyz));
		x++;
	}
	prev = line_node;
}
