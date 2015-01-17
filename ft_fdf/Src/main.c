/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:27:00 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/17 18:46:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_fdf(argv[1], WIDTH, HEIGHT, 1);
	else if (argc == 5)
		ft_fdf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]));
	else
	{
		ft_putstr("ERROR X100 : 4 arguements asked \n");
		ft_putstr("Exemple : 'prog.mlx 1800 1800 1'");
		ft_putendl(" or asked at Barbare for more help :)");
	}
	return (0);
}
