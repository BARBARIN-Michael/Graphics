/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:51:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 12:02:02 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_error(const char *str_error,const char *name_log, int error_type)
{
	if (error_type > 1)
	{
		ft_printf(C_RED"FATAL ERROR ["C_NONE"%s"C_RED"] : "C_NONE"%s\n");
		exit (error_type);
	}
	else
	{
		ft_printf(C_RED"ERROR ["C_NONE"%s"C_RED"] : "C_NONE"%s\n");
		return ;
	}
}
