/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 10:58:45 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/03 14:57:15 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft/includes/libft.h"

# define L_PTR_16 16

void	ft_debug_ptr(void **ptr, char *nptr, int end_cycle)
{
	static int cycle = 0;
	int fd;

/* *****************************************************
 * On annonce le cycle du Debug avec le cycle a 0
 * D'abord on donne les regles
 * On lance le cycle continu avec le cycle a 1
 * Ensuite on termine manuellement le cycle en placant le cycle a 2
 * 		Cela aura pour effet de terminer le cycle jusqu'a la fin de la fonction
 * Enfin le debuf ne se fera plus au passage de cycle a -1
 * Pour le relancer il suffit de le remettre a 0 ou 1
 * **************************************************** */

# if cycle == 0
	fd = open("Debug.DEB", O_RDWR);

	ft_putstr_fd(C_GREEN, fd);
	ft_putendl_fd(C_BOLD" *********** DEBUG ANNOUCEMENT *********** "C_GREEN, fd);
	ft_putendl_fd(C_RED"* "C_GREEN"On annonce le cycle du Debug avec le cycle a 0", fd);
 	ft_putendl_fd(C_RED"* "C_GREEN"D'abord on donne les regles", fd);
 	ft_putendl_fd(C_RED"* "C_GREEN"* On lance le cycle continu avec le cycle a 1", fd);
 	ft_putendl_fd(C_RED"* "C_GREEN"* Ensuite on termine manuellement le cycle en placant le cycle a 2", fd);
 	ft_putendl_fd(C_RED"* "C_GREEN"* \tCela aura pour effet de terminer le cycle jusqu'a la fin de la fonction", fd);
 	ft_putendl_fd(C_RED"* "C_GREEN"* Enfin le debuf ne se fera plus au passage de cycle a -1", fd);
	ft_putendl_fd(C_BOLD" *********** FIN DEBUG  *********** ", fd);
	ft_putstr("\n\n\n");
	cycle = 1;
#endif

#if cycle == 1
	/* *****************************
	 * On annonce le nom du pointeur :
	 * ***************************** */
	ft_putstr_fd(C_BOLD" ******************* ", fd);
	ft_putstr_fd(C_BLUE"Pointeur identifie \"", fd);
	ft_putstr_fd(C_BOLD" ******************* ", fd);
	ft_putstr_fd(C_RED, fd);
	ft_putstr_fd(nptr, fd);
	ft_putendl_fd(C_BLUE"\"", fd);
	
	/* *****************************
	 * On annonce le nom du pointeur :
	 * ***************************** */
	ft_putstr_fd(C_BLUE"Pointeur identifie \"", fd);
	ft_putstr_fd(C_RED, fd);
	ft_putstr_fd(nptr, fd);
#endif
}

static char *get_add_ptr(void const *p)
{
	unsigned long	adr;
	char const		*basehexa;
	char			*ptr;
	char			res[9];
	int				i;

	adr = (unsigned long) p;
	basehexa = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = basehexa[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = basehexa[(adr % 16)];
	ptr = ft_memalloc(L_PTR_16 + 1);
	ptr = ft_strcat(ptr, "0x");
	while (i < 9)
	{
		ptr[i + 2] = res[i];
		i++;
	}
	return (ptr);
}
