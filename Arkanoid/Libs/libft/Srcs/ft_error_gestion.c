/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agauci-d <agauci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 17:04:01 by agauci-d          #+#    #+#             */
/*   Updated: 2015/04/08 18:26:33 by agauci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

void ft_error_gestion(char *s, int fd)
{
	ft_putstr_col("Error: ", RED, fd);
	ft_putstr_fd(s, 2);
	exit(-1);
}
