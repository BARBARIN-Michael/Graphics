/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:45:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 19:07:53 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <libft.h>

void		ft_exit(t_env *env)
{
	int		*tmp;
	int		cmp;

	cmp = 0;
	while (cmp < 10)
		mlx_destroy_image(env->mlx.mlx_ptr, env->mlx.img[cmp++].img);
	cmp = 14;
	while (cmp < 18)
		mlx_destroy_image(env->mlx.mlx_ptr, env->mlx.img[cmp++].img);
	mlx_destroy_window(env->mlx.mlx_ptr, env->mlx.win_ptr);
	free(env->datagame);
	free(env->datacam);
	while (env->map_max.y)
		free(env->world_map->line[env->map_max.y--]);
	free(env->world_map);
	exit(0);
}

void		ft_exec(char *file, char *title, int mode, t_screen wh)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	env = (t_env) {.wh = wh, .title = title, .mode = mode, .initial = 1,
					.nb_px = 4};
	env.world_map = malloc(sizeof(t_map));
	env.datagame = malloc(sizeof(t_datagame));
	env.datacam = malloc(sizeof(t_datacam));
	ft_parse(file, &env);
	ft_init_mlx(&env);
	ft_init_sprite(&env);
	ft_setupfcts(env.fct_key, (void *)0);
	first_init(&env);
	mlx_do_key_autorepeaton(env.mlx.mlx_ptr);
	mlx_loop_hook(env.mlx.mlx_ptr, &loop_hook, &env);
	mlx_hook(env.mlx.win_ptr, 2, (1L << 0), &key_press, &env);
	mlx_hook(env.mlx.win_ptr, 3, (1L << 1), &key_release, &env);
	mlx_loop(env.mlx.mlx_ptr);
}
