/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:48 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/03 16:56:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <arka.h>
#include <get_next_line.h>

static int		get_line(char *str)
{
	int			nbr_line;

	nbr_line = get_nbr_line(str);
	return (nbr_line);
}

static void		ft_insert_map(char *str, t_coord xy, t_env *env)
{
	static int		**map = NULL;
	int				*line;
	int				cmp;
	char			**str_split;

	cmp = -1;
	if (!map)
	{
		if (!(map = (int **)malloc(sizeof(int *) * env->world_map->nbr_line)))
			F_ERR("Cannot allocate : memory full", "insert_line");
		env->world_map->line = map;
	}
	if (!(line = (int *)malloc(sizeof(int *) * (xy.x + 1))))
		F_ERR("Cannot allocate : memory full", "insert_line");
	str_split = ft_strsplit(str, ',');
	while (++cmp < xy.x)
	{
		line[cmp] = ft_atoi(str_split[cmp]);
		free(str_split[cmp]);
	}
	free(str_split);
	map[xy.y] = line;
}

void			ft_parse(char *filename, t_env *env)
{
	int			fd;
	int			rslt;
	char		*str;
	t_coord		xy;

	if ((env->world_map->nbr_line = get_line(filename)) < 2)
		N_ERR("Cannot open file", "Parser");
	fd = open(filename, O_RDONLY);
xy = (t_coord) {.x = 0, .y = 0};
	str = NULL;
	while ((rslt = get_next_line(fd, &str)) > 0)
	{
		if (env->map_max.x == 0 || env->map_max.x == xy.x)
			env->map_max.x = xy.x;
		else
			N_ERR("Invalide map_max", "ft_parse");
		xy.x = ft_count_split(str, ',');
		ft_insert_map(str, xy, env);
		xy.y++;
		ft_strdel(&str);
	}
	free(str);
	env->map_max.y = xy.y - 1;
	close(fd);
	if (rslt < 0)
		N_ERR("Cannot open file", "Parser");
}
