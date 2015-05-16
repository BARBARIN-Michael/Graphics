/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 19:28:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 04:46:03 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>
# include <unistd.h>
# define BUFF_SIZE 1048

typedef struct	s_var_gnl
{
	char		*s1;
	char		*s2;
	int			rslt;
	int			fd;
}				t_vargnl;

int				get_next_line(int fd, char **line);
int				get_nbr_line(char *file);

#endif
