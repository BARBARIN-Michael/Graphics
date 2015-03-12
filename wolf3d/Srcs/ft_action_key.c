/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:54:27 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 01:45:29 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

void	ft_action_move_up(t_env *env, int state)
{
	env->movement.up = state;
}

void	ft_action_move_down(t_env *env, int state)
{
	env->movement.down = state;
}

void	ft_action_move_left(t_env *env, int state)
{
	env->movement.left = state;
}

void	ft_action_move_right(t_env *env, int state)
{
	env->movement.right = state;
}

void	ft_manage_move(t_env *env)
{
	if (env->movement.up)
		ft_movement_up(env);
	if (env->movement.left)
		ft_movement_left(env);
	if (env->movement.right)
		ft_movement_right(env);
	if (env->movement.down)
		ft_movement_down(env);
}
