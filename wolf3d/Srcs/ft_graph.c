/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:01:16 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <time.h>

void	ft_graph(t_env *env)
{
	t_time		*time;
	struct timeval timeval;

	time = &env->datagame->time;
	gettimeofday(&timeval, NULL);
	time->time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	env->fps = (int)(time->time - time->oldtime);
	printf(C_RED"deuxieme lecture : \n "C_GREEN"%s\n\n", env->mlx.data);
	ft_putimage(env);
	ft_bzero(env->mlx.data, env->mlx.sizeline * env->wh.height);
}
