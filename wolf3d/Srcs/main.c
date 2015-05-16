/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:40:50 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 19:06:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

int		main(int argc, char **argv)
{
	t_screen screen;

	screen = (t_screen){1000, 800};
	if (argc == 1)
		ft_exec("wolf3d.42", "Wolf3d.42", 0, screen);
	else if (argc == 2)
		ft_exec(argv[1], argv[1], 1, screen);
	else
		ft_putstr("Veuillez saisir aucun parametre ou bien le fichier map\n");
	return (0);
}
