/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:51:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 15:05:17 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_error(const char *str_error, const char *name_log, int error_type)
{
	if (error_type > 1)
	{
		ft_putstr("FATAL ERROR [");
		ft_putstr(str_error);
		ft_putstr("] : ");
		ft_putendl(name_log);
		exit(error_type);
	}
	else
	{
		ft_putstr("ERROR [");
		ft_putstr(str_error);
		ft_putstr("] : ");
		ft_putendl(name_log);
		return ;
	}
}
