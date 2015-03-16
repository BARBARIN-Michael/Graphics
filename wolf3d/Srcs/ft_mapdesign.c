/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdesign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:54:27 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 01:45:29 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

void		ft_mapdesign(t_env *env)
{
	t_coord	xy;
	char	*copy;
	t_rgb	rgb;

	xy = (t_coord) {.x = 0, .y = 0};
	while (xy.y <= env->map_max.y)
	{
		if (xy.x == env->map_max.x - 1)
		{
			xy.x = 0;
			xy.y++;
			continue ;
		}
		if (xy.x == abs(env->datagame->pos.y)
				&& xy.y == abs(env->datagame->pos.x))
			ft_draw_map(xy.x, xy.y, env, (t_rgb){0xFF, 0x00, 0x00});
		else if (env->world_map->line[xy.y][xy.x] == 0)
		{
			ft_draw_map(xy.x, xy.y, env, (t_rgb){0xAF, 0xFA, 0xAF});
			ft_draw_map(xy.x + 1, xy.y, env, (t_rgb){0xAF, 0xFA, 0xAF});
			ft_draw_map(xy.x, xy.y + 1, env, (t_rgb){0xAF, 0xFA, 0xAF});
			ft_draw_map(xy.x + 1, xy.y + 1, env, (t_rgb){0xAF, 0xFA, 0xAF});
		}
		else
		{
			rgb = ft_get_color_by_pt(env->world_map->line[xy.y][xy.x], 1);
			ft_draw_map(xy.x, xy.y, env, rgb);
		}
		xy.x++;
	}
}
