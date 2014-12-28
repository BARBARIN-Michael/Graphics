/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/28 17:48:17 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../Include/ft_fdf.h"

static void		ft_icd_mlx(t_mlx *mlx, t_list *lst, int state)
{
	t_list *listadel;

	if (state == 0)
	{
		mlx->mlx_ptr = mlx_init();
		mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
		mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->sizeline, &mlx->endian);
	}
	else
	{
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, TITLE_WIN);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	sleep(100);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		while (lst != NULL)
		{
			listadel = lst;
			free(lst->content);
			lst = lst->next;
			free(listadel);
		}
	}
}

void	ft_fdf(char *str)
{
	t_mlx		mlx;
	t_list		*lstfile;
	size_vector vectlen;

	lstfile = ft_parsefile(str);
	ft_icd_mlx(&mlx, lstfile, 0);
	vectlen = WIDTH / x_max(lstfile);
	draw_fdf(&mlx, lstfile, vectlen);
	ft_icd_mlx(&mlx, lstfile, 1);
}
