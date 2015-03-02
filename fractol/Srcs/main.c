/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:27:00 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/28 21:51:10 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fractol.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_exec(argv[1], 800, 600, "mandelbrot");
	else
	{
		ft_putstr("ERROR X100 : just one arguement asked \n");
		ft_putstr("Exemple : 'prog.mlx mandelbrot'\n");
		ft_putstr("Exemple : 'prog.mlx julia'\n");
		ft_putstr("Exemple : 'prog.mlx \"une autre\"'\n");
		ft_putendl(" or asked at Barbare for more help :)");
	}
	return (0);
}
