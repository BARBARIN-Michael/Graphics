/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:40:50 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/17 16:31:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <ft_printf.h>

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_exec("../wolf.42", "Wolf 3D example map", 0, (t_screen) {800, 600});
	else if (argc == 2)
		ft_exec(argv[1], argv[1], 1, (t_screen) {800, 600});
	else
		ft_putstr("Veuillez saisir aucun parametre ou bien le fichier map\n");
	return (0);
}
