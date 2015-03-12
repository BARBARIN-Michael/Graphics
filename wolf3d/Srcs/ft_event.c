/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:01:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 06:51:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_event.h>
#include <ft_wolf.h>

int		mouse_event(int button, int x, int y, t_env *env)
{
	if (button == MOUSE_BT_LEFT)
		ft_action_mouse_left(x, y, env);
	else if (button == MOUSE_BT_RIGHT)
		ft_action_mouse_right(x, y, env);
	else if (button == MOUSE_BT_MID)
		ft_action_mouse_mid(x, y, env);
}

int		key_press(int key, t_env *env)
{
	if (key == KEY_W)
		ft_action_move_up(env, 1);
	else if (key == KEY_S)
		ft_action_move_down(env, 1);
	else if (key == KEY_A)
		ft_action_move_right(env, 1);
	else if (key == KEY_D)
		ft_action_move_left(env, 1);
	else if (key == KEY_ESCAPE)
		ft_exit(env);
}

int		key_release(int key, t_env *env)
{
	if (key == KEY_W)
		ft_action_move_up(env, 0);
	else if (key == KEY_S)
		ft_action_move_down(env, 0);
	else if (key == KEY_A)
		ft_action_move_right(env, 0);
	else if (key == KEY_D)
		ft_action_move_left(env, 0);
}

int		loop_hook(t_env *env)
{
	int		x;

	x = 0;
	//if (!(int)env->movement.up)
	//	return ;
	while (x < env->wh.height)
	{
		init_player_position(x, env);
		ft_engine_rc(x, env);
		x++;
	}
	ft_graph(env);
}