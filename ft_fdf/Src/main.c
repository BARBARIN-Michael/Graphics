/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:27:00 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/09 13:21:59 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

int		main(int argc, char **argv)
{
	argc = argc;
	argv = argv;

	if (argc == 2)
		ft_fdf(argv[1], WIDTH, HEIGHT);
	else
		ft_fdf(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}
