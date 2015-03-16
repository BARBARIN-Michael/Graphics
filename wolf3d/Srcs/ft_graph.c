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
	struct timeval timeval;

	env->datagame->time.oldtime = env->datagame->time.time;
	gettimeofday(&timeval, NULL);
	env->datagame->time.time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000.0;
	env->framerate = (env->datagame->time.time - env->datagame->time.oldtime) / 1000.0;
	env->fps = 1.0 / env->framerate;
	ft_putimage(env, env->mlx.img);
}
