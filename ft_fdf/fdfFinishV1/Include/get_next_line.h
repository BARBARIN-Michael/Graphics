/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 19:28:15 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/14 13:20:34 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>
# include <unistd.h>
# define BUFF_SIZE 1048

typedef struct	s_var
{
	char		*s1;
	char		*s2;
	int			rslt;
	int			fd;
}				t_var;
int				get_next_line(int fd, char **line);

#endif
