/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:01:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/17 16:32:36 by mbarbari         ###   ########.fr       */
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
	if (key == KEY_W || key == ARROW_UP)
		ft_action_move_up(env, TRUE);
	else if (key == KEY_S || key == ARROW_DOWN)
		ft_action_move_down(env, TRUE);
	else if (key == KEY_D || key == ARROW_RIGHT)
		ft_action_move_right(env, TRUE);
	else if (key == KEY_A || key == ARROW_LEFT)
		ft_action_move_left(env, TRUE);
	else if (key == KEY_1)
		ft_print_map(env);
	else if (key == KEY_2)
	{
		env->map = env->map == 0 ? 1 : 0;
		env->initial = 1;
		loop_hook(env);
	}
	else if (key == KEY_0)
		env->speed += 0.00001;
	else if (key == KEY_9)
		env->speed -= 0.00001;
	else if (key == KEY_ESCAPE)
		ft_exit(env);
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
}

int		loop_hook(t_env *env)
{
	int		x;

	x = 0;
	if (env->map == 1 && env->cmp_map++ > 10)
	{
		ft_mapdesign(env);
		env->cmp_map = 0;
	}
	if (	env->initial == 0 && !env->movement.up && !env->movement.down &&
			!env->movement.left && !env->movement.right)
			return (0);
	env->initial = 0;
	while (x < env->wh.width)
	{
		init_player_position(x, env);
		ft_engine_rc(x, env);
		x++;
	}
	ft_graph(env);
}
