/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:48 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:16:13 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <ft_wolf.h>
#include <get_next_line.h>

static int		get_line(char *str)
{
	int			nbr_line;

	nbr_line = get_nbr_line(str);
	return (nbr_line);
}

static void		ft_insert_map(char *str, t_coord xy, t_env *env)
{
	static int		**map;
	int				*line;
	int				cmp;
	char			**str_split;

	cmp = 0;
	if (!(map = (int **)malloc(sizeof(int *) * env->world_map->nbr_line)))
		ft_error("Cannot allocate : memory full", "ERROR X01.1:insert_map", 1);
	if (!(line = (int *)malloc(sizeof(int *) * (xy.x + 1))))
		ft_error("Cannot allocate : memory full", "ERROR X01.1:insert_line", 1);
	line[0] = xy.x;
	str_split = ft_nstrsplit(str, ',', xy.x);
	while (cmp < xy.x)
	{
		line[cmp + 1] = ft_atoi(str_split[cmp]);
		printf(C_CYAN"%d ", line[cmp + 1]);
		cmp++;
	}
	printf(C_NONE"\n");
	map[xy.y] = &line[0];
	printf(C_RED"Si je lit ici : %d\n", map[0][0]);
	if (xy.y == env->world_map->nbr_line)
		env->world_map->line = map;
}

void			ft_parse(char *filename, t_env *env)
{
	int			fd;
	int			rslt;
	char		*str;
	t_coord		xy;

	if ((env->world_map->nbr_line = get_line(filename)) < 0)
		ft_error("Cannot open file", "ERROR X01.0:Parser:", 1);
	fd = open(filename, O_RDONLY);
	xy = (t_coord) {.x = 0, .y = 0};
	printf(C_RED"La map : \n");
	while ((rslt = get_next_line(fd, &str)) > 0)
	{
		if (!str[0])
			continue ;
		xy.x = ft_count_split(str, ',');
		ft_insert_map(str, xy, env);
		xy.y++;
		ft_strdel(&str);
	}
	close(fd);
	rslt < 0 ? ft_error("Cannot open file", "ERROR X01.0:Parser:", 1), 1 : 0;
}
