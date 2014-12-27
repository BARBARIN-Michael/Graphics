/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:22:04 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/27 10:43:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_fdf.h"

static void		ft_icd_mlx(t_mlx *mlx, t_list *lst, int state, char *str)
{
	if (state == 0)
	{
		mlx->mlx_ptr = mlx_init();
		lst = ft_parsefile(str);
		mlx->img = mlx_new_image(mlx->mlx_ptr, x_max(lst), y_max(lst));
		mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->sizeline, &mlx->endian);
	}
	else
	{
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, TITLE_WIN);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 25, 25);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		while (lst != NULL)
		{
			ft_strdel(lst->content);
			lst = lst->next;
		}
	}
}

void	ft_fdf(char *str)
{
	t_mlx		mlx;
	t_list		*lstfile;
	size_vector vectlen;

	lstfile = NULL;
	ft_icd_mlx(&mlx, lstfile, 0, str);
	vectlen = WIDTH / x_max(lstfile);
	draw_fdf(&mlx, lstfile, vectlen);
	ft_icd_mlx(&mlx, lstfile, 1, NULL);
}
