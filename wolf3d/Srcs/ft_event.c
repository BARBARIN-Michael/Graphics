/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:01:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 15:08:33 by mbarbari         ###   ########.fr       */
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
	return (0);
}

int		key_press(int key, t_env *env)
{
	if (key == KEY_W || key == ARROW_UP)
		ft_action_move_up(env, TRUE);
	else if (key == KEY_E)
		ft_action_kill(env, TRUE);
	else if (key == KEY_S || key == ARROW_DOWN)
		ft_action_move_down(env, TRUE);
	else if (key == KEY_D || key == ARROW_RIGHT)
		ft_action_move_right(env, TRUE);
	else if (key == KEY_A || key == ARROW_LEFT)
		ft_action_move_left(env, TRUE);
	else if (key == KEY_1)
		env->mode = env->mode == 0 ? 1 : 0;
	else if (key == KEY_2)
	{
		env->map = env->map == 0 ? 1 : 0;
		env->initial = 1;
	}
	else if (key == KEY_0)
		env->speed += 0.00001;
	else if (key == KEY_9)
		env->speed -= 0.00001;
	else if (key == KEY_ESCAPE)
		ft_exit(env);
	return (0);
}

int		key_release(int key, t_env *env)
{
	if (key == KEY_W || key == ARROW_UP)
		ft_action_move_up(env, FALSE);
	else if (key == KEY_S || key == ARROW_DOWN)
		ft_action_move_down(env, FALSE);
	else if (key == KEY_D || key == ARROW_RIGHT)
		ft_action_move_right(env, FALSE);
	else if (key == KEY_A || key == ARROW_LEFT)
		ft_action_move_left(env, FALSE);
	else if (key == KEY_E)
		ft_action_kill(env, FALSE);
	return (0);
}

int		loop_hook(t_env *env)
{
	int		x;

	x = 0;
	env->initial = 0;
	while (x < env->wh.width)
	{
		init_player_position(x, env);
		if (env->mode == 0)
			ft_engine_rc(x, env);
		else
			ft_engine_tiles_rc(x, env);
		x++;
	}
	if (env->map == 1)
		ft_mapdesign(env);
	ft_graph(env);
	mlx_do_sync(env->mlx.mlx_ptr);
	return (0);
}
