/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 10:30:20 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/03 13:53:56 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arka.h>

int		main(int argc, char **argv)
{
	t_screen screen;

	screen = (t_screen){1000, 800};
	if (argc == 1)
		ft_exec("break1.42", "break1.42", 0, screen);
	else if (argc == 2)
		ft_exec(argv[1], argv[1], 1, screen);
	else
		ft_putstr("Veuillez saisir aucun parametre ou bien le fichier map\n");
	return (0);

}
