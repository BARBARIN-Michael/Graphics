/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupfcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 12:11:18 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 04:43:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static void	init_fcts(t_fcts_keypad *keypad, t_fcts_mouse *mouse)
{
	int		cmp;

	cmp = 0;
	while (cmp < sizeof(char))
	{
		if (keypad)
			keypad[cmp] = (void *)0;
		if (mouse)
			mouse[cmp] = (void *)0;
		cmp++;
	}
}

static void	setup_keypad(t_fcts_keypad *keypad)
{
	keypad['w'] = &ft_action_move_up;
	keypad['s'] = &ft_action_move_down;
	keypad['a'] = &ft_action_move_left;
	keypad['d'] = &ft_action_move_right;
	//keypad['m'] = &ft_newmode;
}

static void	setup_mouse(t_fcts_mouse *mouse)
{
	return ;
}

void		ft_setupfcts(t_fcts_keypad *keypad, t_fcts_mouse *mouse)
{
	init_fcts(keypad, mouse);
	if (keypad)
		setup_keypad(keypad);
	if (mouse)
		setup_mouse(mouse);
}
