/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/24 03:12:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_fdf.h"

void	ft_fdf(char *str)
{
	t_mlx		mlx;
	t_list		*lstfile;

	ft_icd_mlx(&mlx, lstfile, 0);
	draw_fdf(&mlx, lstfile)
	ft_icd_mlx(&mlx, lstfile, 1);
}

static void		ft_icd_mlx(t_mlx *mlx, t_list *lst, int state)
{
	if (stat == 0)
	{
		mlx->mlx->ptr = mlx->init();
		lstfile = ft_parsefile(str);
		mlx->img = mlx->new_image(mlx->mlx->ptr, x_max(lstfile), y_max(lstfile);
		mlx->data = mlx->get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	}
	else
	{
		mlx->win_ptr = mlx->new_window(mlx->mlx->ptr, HEIGHT, WIDTH, TITLE_WIN);
		mlx->put_image_to_window(mlx->mlx->ptr, mlx->win_ptr, mlx->img, 25, 25);
		mlx->destroy_image(mlx->mlx->ptr, mlx->img);
		mlx->destroy_window(mlx->mlx->ptr, mlx->win_ptr);
	}
}
