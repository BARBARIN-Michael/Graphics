/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 12:22:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 14:39:07 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

void	ft_action_kill(t_env *env, int state)
{
	t_coord new;

	if (state == 1)
	{
		new.x = (int)(env->datagame->pos.x + env->datagame->dir.x * 1);
		new.y = (int)(env->datagame->pos.y + env->datagame->dir.y * 1);
		if (env->world_map->line[new.x][(int)(env->datagame->pos.y)] > 0 &&
			env->world_map->line[new.x][(int)(env->datagame->pos.y)] < 8)
			env->world_map->line[new.x][(int)(env->datagame->pos.y)] = 0;
		if (env->world_map->line[(int)(env->datagame->pos.x)][new.y] > 0 &&
			env->world_map->line[(int)(env->datagame->pos.x)][new.y] < 8)
			env->world_map->line[(int)(env->datagame->pos.x)][new.y] = 0;
		env->frappe = 1;
	}
	else
		env->frappe = 0;
}
