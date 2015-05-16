/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/27 19:05:25 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <mlx.h>

static void	init_img(t_env *env, int img, char *path, t_screen wh)
{
	int width;
	int height;

	width = wh.width;
	height = wh.height;
	if (path == NULL)
	{
		env->mlx.img[img].img = mlx_new_image(env->mlx.mlx_ptr,
												wh.width,
												wh.height);
	}
	else
	{
		if (!(env->mlx.img[img].img = mlx_xpm_file_to_image(env->mlx.mlx_ptr,
														path,
														&width,
														&height)))
			ft_error("IMG cannot Created", "init X10.2", 2);
	}
	env->mlx.img[img].data = mlx_get_data_addr(env->mlx.img[img].img,
												&env->mlx.img[img].bpp,
												&env->mlx.img[img].sizeline,
												&env->mlx.img[img].endian);
	env->mlx.img[img].wh = wh;
}

void		ft_init_mlx(t_env *env)
{
	t_screen wh;
	t_screen map;

	wh = env->wh;
	if (!(env->mlx.mlx_ptr = mlx_init()))
		ft_error("MLX cannot initialized", "init X10.1", 2);
	env->mlx.win_ptr = mlx_new_window(env->mlx.mlx_ptr,
										wh.width,
										wh.height,
										env->title);
	env->wh.height++;
	env->wh.width++;
	init_img(env, 0, NULL, (t_screen){wh.width + 1, wh.height + 1});
}

void		ft_init_sprite(t_env *env)
{
	init_img(env, 1, MUR_BOIS, (t_screen){256, 256});
	init_img(env, 2, FLOOR, (t_screen){512, 512});
	init_img(env, 3, MUR_BOIS, (t_screen){256, 256});
	init_img(env, 4, TILE_Y_B, (t_screen){512, 512});
	init_img(env, 6, FLAMES, (t_screen){128, 64});
	init_img(env, 8, BRIQUE, (t_screen){512, 512});
	init_img(env, 9, BRIQUE, (t_screen){512, 512});
	init_img(env, 7, PLASMA, (t_screen){128, 128});
	init_img(env, 5, REDROCK, (t_screen){512, 512});
	init_img(env, 14, WEAPON_0, (t_screen){455, 341});
	init_img(env, 15, WEAPON_1, (t_screen){455, 341});
	init_img(env, 16, WEAPON_2, (t_screen){455, 341});
	init_img(env, 17, WEAPON_3, (t_screen){455, 341});
	init_img(env, 18, WEAPON_F, (t_screen){455, 341});
}

static void	testing_sens(t_env *env)
{
	if (env->sens == 0 && env->anim < 40)
		env->anim += 2;
	else
	{
		env->sens = 1;
	}
	if (env->sens == 1 && env->anim >= 0)
		env->anim -= 2;
	else
	{
		env->sens = 0;
	}
}

void		ft_putweapon(t_env *env)
{
	static t_screen wh_weap = {0, 0};

	if (wh_weap.width == 0)
	{
		wh_weap.width = env->wh.width / 2 - (env->mlx.img[14].wh.width / 2);
		wh_weap.height = env->wh.height - env->mlx.img[14].wh.height;
	}
	testing_sens(env);
	if (env->frappe == 1)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img[18].img, wh_weap.width, wh_weap.height);
	else if (env->anim < 10)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img[14].img, wh_weap.width, wh_weap.height);
	else if (env->anim < 20)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img[15].img, wh_weap.width, wh_weap.height);
	else if (env->anim < 30)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img[16].img, wh_weap.width, wh_weap.height);
	else if (env->anim < 50)
		mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr,
				env->mlx.img[17].img, wh_weap.width, wh_weap.height);
}
