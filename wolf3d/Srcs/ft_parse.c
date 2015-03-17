/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:48 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/17 13:45:10 by mbarbari         ###   ########.fr       */
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
			ft_error("Allocate : memory full", "ERROR X01.1:insert_map", 1);
		env->world_map->line = map;
	}
	if (!(line = (int *)malloc(sizeof(int *) * (xy.x + 1))))
		ft_error("Cannot allocate : memory full", "ERROR X01.1:insert_line", 1);
	str_split = ft_nstrsplit(str, ',', xy.x);
	while (++cmp < xy.x)
		line[cmp] = ft_atoi(str_split[cmp]);
	while (cmp > -1)
	{
		free(str_split[cmp]);
		cmp--;
	}
	free(str_split);
	map[xy.y] = line;
}

static void test_map(t_env *env)
{
	int		cmp_x;
	int		cmp_y;

	cmp_x = -1;
	cmp_y = -1;
	while (++cmp_x < env->map_max.x)
	{
		if (env->world_map->line[0][cmp_x] == 0 ||
			env->world_map->line[env->map_max.y][cmp_x] == 0)
			ft_error("Invalide map, Cheack the extremity wall",
						"ERROR X01:3:testmap", 1);
	}
	while (++cmp_y <= env->map_max.y)
	{
		if (env->world_map->line[cmp_y][0] == 0 ||
			env->world_map->line[cmp_y][env->map_max.x - 1] == 0)
			{
			ft_error("Invalide map, Cheack the extremity wall",
						"ERROR X01:2:testmap", 1);
			printf("test map : line[%d][%d] = %d \n", cmp_y, env->map_max.x, env->world_map->line[cmp_y][env->map_max.x]);
			}
		cmp_y++;
	}
}

void			ft_parse(char *filename, t_env *env)
{
	int			fd;
	int			rslt;
	char		*str;
	t_coord		xy;

	if ((env->world_map->nbr_line = get_line(filename)) < 2)
		ft_error("Cannot open file", "ERROR X01.0:Parser:", 0);
	fd = open(filename, O_RDONLY);
	xy = (t_coord) {.x = 0, .y = 0};
	str = NULL;
	while ((rslt = get_next_line(fd, &str)) > 0)
	{
		if (env->map_max.x == 0 || env->map_max.x == xy.x)
			env->map_max.x = xy.x;
		else
			ft_error("Invalide map_max", "ERROR X01.1:Parser:", 2);
		xy.x = ft_count_split(str, ',');
		ft_insert_map(str, xy, env);
		xy.y++;
		free(str);
	}
	free(str);
	env->map_max.y = xy.y - 1;
	test_map(env);
	close(fd);
	rslt < 0 ? ft_error("Cannot open file", "ERROR X01.0:Parser:", 1), 1 : 0;
}

void			ft_print_map(t_env *env)
{
	t_coord	cmp;
	char	*copy;

	cmp = (t_coord) {.x = 0, .y = 0};
	while (cmp.y <= env->map_max.y)
	{
		if (cmp.x == env->map_max.x - 1)
		{
			write(1, "\n", 1);
			cmp.x = 0;
			cmp.y++;
		}
		else
		{
			if (cmp.x++ == abs(env->datagame->pos.y) && cmp.y == abs(env->datagame->pos.x))
				ft_putstr(C_CYAN"T "C_BROWN);
			else
				ft_nputstr(2, ft_itoa(env->world_map->line[cmp.y][cmp.x]), " ");
		}
	}
}
