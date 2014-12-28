/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:27:00 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/28 11:24:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_fdf.h"

int		main(int argc, char **argv)
{
	argc = argc;
	argv = argv;

	// On appel la fonction de fenetrage
	ft_fdf(argv[1]);
	return (0);
}
