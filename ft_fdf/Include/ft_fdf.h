/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:30:10 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/29 17:57:26 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define WIDTH 600
# define HEIGHT 600
# define OFFSET_W 400
# define OFFSET_H 550
# define OFFSET_XY 15
# define OFFSET_ISOY 0.6
# define OFFSET_ISOX 0.82
# define TITLE_WIN "FDF a la BARBARE"
# define RED 0xFF0000
# define GRE 0x00FF00
# define BLU 0x0000FF

#include <mlx.h>
#include <libft.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "get_next_line.h"

typedef unsigned int color;
typedef unsigned int size_vector;

typedef struct	s_mlx
{
	void          *mlx_ptr;
	void          *win_ptr;
	void          *img;
	char          *data;
	int           width;
	int           height;
	int           bpp;
	int           sizeline;
	int           endian;
	unsigned int  color;
	char          *data_color;
}				t_mlx;

typedef struct	s_coord
{
	double x1;
	double y1;
	double x2;
	double y2;
}				t_coord;

typedef struct	s_axe
{
	double x;
	double y;
	double z;
}				t_axe;

typedef struct	s_node
{
	t_axe	xyz;
	void	*first_xnode;
	void	*left_node;
	void	*right_node;
}				t_node;

// FT_FDF.H
void			ft_fdf(char *str);

// FT_GRAPH.H
void			draw_pixel_to_img(int x, int y, t_mlx *mlx,  color unitcolor);
void			ecrire_vecteur(t_coord cnew, double x, double z); // a supprimer
void			draw_line(t_coord c1, t_mlx *mlx, color col);
void			draw_fdf(t_mlx *mlx, t_list *lf, size_vector lv);

// FT_ALGOFDF.H
double			coord_x_iso(double x, double y);
double			coord_y_iso(double x, double y, double z);
int				x_max(t_list *lst);
int				y_max(t_list *lst);

// FT_PARSE.H
t_list			*ft_parsefile(char *file);
unsigned int	ft_getvalue(char *str, int x);
int				ft_coord_nbr(char *str);
void			ft_insert_map(char *str);

// FT_MATH.H
int				direction_vector(int x1, int y1, int x2, int y2);
t_coord			rotate_direction(t_coord cl);
t_coord			trans_vectoriel(t_coord vector, double trans);
t_coord			new_vector(double x1, double y1, double x2, double y2);
t_coord			cpy_vector(t_coord v_out, t_coord v_in);

// FT_LIST.H
t_node			*ft_new_lstfdf(t_node *first, t_axe xyz);
void			ft_lstaddbackfdf(t_node **first, t_node *new, int cr);
void			ft_update_prevnode(t_node **first, t_node *new, int cr);
void			ft_print_map(t_node *map, int x, int y);

#endif
