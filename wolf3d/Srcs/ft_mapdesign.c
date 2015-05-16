/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdesign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:20:33 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/01 10:55:48 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <math.h>

static int	testing(t_coord *xy, t_env *env)
{
	if (xy->x == env->map_max.x - 1)
	{
		xy->x = 0;
		xy->y++;
		return (1);
	}
	return (0);
}

void		ft_mapdesign(t_env *env)
{
	t_coord		xy;
	t_rgb		rgb;
	t_move		data;

	ft_bzero(&data, sizeof(data));
	xy = (t_coord) {.x = 0, .y = 0};
	while (xy.y <= env->map_max.y)
	{
		if (testing(&xy, env) == 1)
			continue ;
		if (xy.x == abs((int)env->datagame->pos.y)
				&& xy.y == abs((int)env->datagame->pos.x))
			ft_draw_map(xy.x, xy.y, env, (t_rgb){0xFF, 0x00, 0x00});
		else if (env->world_map->line[xy.y][xy.x] == 0)
			ft_draw_map(xy.x, xy.y, env, (t_rgb){0xAF, 0xFA, 0xAF});
		else
		{
			rgb = ft_get_color_by_pt(env->world_map->line[xy.y][xy.x], 1, data);
			ft_draw_map(xy.x, xy.y, env, rgb);
		}
		xy.x++;
	}
}
