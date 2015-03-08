/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:32:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 19:37:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	calc_neg(t_move *data, t_env *env, int mod)
{
	if (mod == 0)
	{
		data.stape.x = -1;
		cam.wall = (cam.raypos.x - cam.map.x) * cam.wall_next;
	}
	else if (mod == 1)
	{
		data.stape.y = -1;
		cam.wall = (cam.raypos.y - cam.map.y) * cam.wall_next;
	}
}

static void	calc_pos(t_move *data, t_env *env, int mod)
{
	if (mod == 0)
	{
		data.stape.x = 1;
		cam.wall = (cam.map.x + 1 - cam.raypos.x) * cam.wall_next;
	}
	else if (mod == 1)
	{
		data.stape.y = 1;
		cam.wall = (cam.map.y + 1 - cam.raypos.y) * cam.wall_next;
	}
}

void		ft_new_calc_movement(t_env *env)
{
	t_move		data;
	t_datacam	cam;
	t_datagame	game;

	cam = &env->datacam;
	game = &env->datagame;
	data.collision = 0;
	if (env->datacam.raydir.x < 0)
	{
		data.stape.x = -1;
		cam.wall = (cam.raypos.x - cam.map.x) * cam.wall_next;
	}
	else
	{
		data.stape.x = 1;
		cam.wall = (cam.raypos.x - cam.map.x) * cam.wall_next;
	}
}
