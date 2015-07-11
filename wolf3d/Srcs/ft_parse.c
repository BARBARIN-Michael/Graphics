/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:48 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/01 14:41:43 by mbarbari         ###   ########.fr       */
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
	static int		**map = NULL;
	int				*line;
	int				cmp;
	char			**str_split;

	cmp = -1;
	if (!map)
	{
		if (!(map = (int **)malloc(sizeof(int *) * env->world_map->nbr_line)))
			ft_error("Allocate : memory full", "ERROR X01.1:insert_map", 2);
		env->world_map->line = map;
	}
	if (!(line = (int *)malloc(sizeof(int *) * (xy.x + 1))))
		ft_error("Cannot allocate : memory full", "ERROR X01.1:insert_line", 2);
	str_split = ft_strsplit(str, ',');
	while (++cmp < xy.x)
	{
		line[cmp] = ft_atoi(str_split[cmp]);
		if (line[cmp] < -9 || line[cmp] > 9)
			ft_error("Invalide map, component wall need -9 to 9",
						"ERROR X01:4:testmap", 2);
		free(str_split[cmp]);
	}
	free(str_split);
	map[xy.y] = line;
}

static void		test_map(t_env *env)
{
	int		cmp_x;
	int		cmp_y;

	cmp_x = -1;
	cmp_y = -1;
	while (++cmp_x < env->map_max.x)
	{
		if (env->world_map->line[0][cmp_x] != 9 ||
			env->world_map->line[1][cmp_x] != 9 ||
			env->world_map->line[env->map_max.y][cmp_x] != 9 ||
			env->world_map->line[env->map_max.y - 1][cmp_x] != 9)
			ft_error("Invalide map, Cheack the extremity wall",
						"ERROR X01:3:testmap", 2);
	}
	while (++cmp_y <= env->map_max.y)
	{
		if (env->world_map->line[cmp_y][0] != 9 ||
			env->world_map->line[cmp_y][1] != 9 ||
			env->world_map->line[cmp_y][env->map_max.x - 1] != 9 ||
			env->world_map->line[cmp_y][env->map_max.x - 2] != 9)
			ft_error("Invalide map, Cheack the extremity wall",
						"ERROR X01:2:testmap", 2);
	}
}

t_coord			ft_parse_tp(t_env *env, t_coord tp1, int tp)
{
	t_coord		xy;
	t_map		*map;

	map = env->world_map;
	xy = (t_coord){0, 0};
	while (xy.y < env->map_max.y)
	{
		xy.x = 0;
		while (xy.x < env->map_max.x - 1)
		{
			if (map->line[xy.y][xy.x] == (tp - 1)
					&& xy.x != tp1.x && xy.y != tp1.y)
				return (xy);
			xy.x++;
		}
		xy.y++;
	}
	return ((t_coord){7, 7});
}

void			ft_parse(char *filename, t_env *env)
{
	int			fd;
	int			rslt;
	char		*str;
	t_coord		xy;

	if ((env->world_map->nbr_line = get_line(filename)) < 2)
		ft_error("Cannot open file", "ERROR X01.0:Parser:", 2);
	fd = open(filename, O_RDONLY);
	xy = (t_coord) {.x = 0, .y = 0};
	str = NULL;
	while ((rslt = get_next_line(fd, &str)) > 0)
	{
		env->map_max.x == 0 || env->map_max.x == xy.x ? env->map_max.x = xy.x, 1
			: ft_error("Invalide map_max", "ERROR X01.1:Parser:", 2), 0;
		xy.x = ft_count_split(str, ',');
		ft_insert_map(str, xy, env);
		xy.y++;
		ft_strdel(&str);
	}
	free(str);
	env->map_max.y = xy.y - 1;
	test_map(env);
	close(fd);
	if (rslt < 0)
		ft_error("Cannot open file", "ERROR X01.0:Parser:", 2);
}
