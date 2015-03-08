/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupfcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 12:11:18 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 13:42:00 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static void	init_fcts(t_fcts_keypad *keypad, t_fcts_mouse *mouse)
{
	int		cmp;

	cmp = 0;
	while (cmp < sizeof(char))
	{
		keypad[cmp] = (void *)0;
		mouse[cmp] = (void *)0;
		cmp++;
	}
}

static void	setup_keypad(t_fcts_keypad *keypad)
{
	keypad['w'] = &ft_updown;
	keypad['s'] = &ft_updown;
	keypad['a'] = &ft_rightleft;
	keypad['d'] = &ft_rightleft;
	keypad['m'] = &ft_newmode;
}

static void	setup_mouse(t_fcts_mouse *mouse)
{
	return ;
}

void		ft_setupfcts(t_fcts_keypad *keypad, t_fcts_mouse *mouse)
{
	init_fcts(keypad, mouse);
	setup_keypad(keypad);
	setup_mouse(mouse);
}
