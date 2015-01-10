/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:27:00 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/10 20:33:33 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

int		main(int argc, char **argv)
{
	argc = argc;
	argv = argv;

/*	if (argc == 2 && ft_strcmp(argv[1], "-h") == 0)
		ft_putendl(C_GREEN"launch program with this template : "C_NONE"
				prog.mlx [name of map] [width height mode :"C_CYAN" optional
				"C_NONE"\n\tMode 1 : maps\n\tMode 2 : aleatoire");
*/	if (argc == 2)
		ft_fdf(argv[1], WIDTH, HEIGHT, 1);
	else if (argc == 5)
		ft_fdf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]));
	else
		ft_putstr("ERROR X100 : 4 arguements asked \n");
		ft_putstr("Exemple : 'prog.mlx 1800 1800 1' ask prog.mlx -h");
		ft_putendl("for more help");
	return (0);
}
