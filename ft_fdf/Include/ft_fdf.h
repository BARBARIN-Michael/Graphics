/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:30:10 by mbarbari          #+#    #+#             */
/*   Updated: 2014/12/30 17:57:51 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define WIDTH 600
# define HEIGHT 600
# define OFFSET_W 300
# define OFFSET_H 250
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

typedef struct	s_vector
{
	double x1;
	double y1;
	double x2;
	double y2;
}				t_vector;

typedef struct	s_axe
{
	int x;
	int y;
	int z;
}				t_axe;

typedef struct	s_node
{
	t_axe	xyz;
	struct s_node	*first_xnode;
	struct s_node	*left_node;
	struct s_node	*right_node;
}				t_node;

// FT_FDF.H
void			ft_fdf(char *str);

// FT_GRAPH.H
void			draw_pixel_to_img(int x, int y, t_mlx *mlx,  color unitcolor);
void			ecrire_vecteur(t_vector cnew, double x, double z); // a supprimer
void			draw_line(t_vector c1, t_mlx *mlx, color col);
void			draw_fdf(t_mlx *mlx, t_node *map, size_vector lv);

// FT_ALGOFDF.H
double			coord_x_iso(int x, int y);
double			coord_y_iso(int x, int y, int z);
int				x_max(t_node *map);
int				y_max(t_node *map);

// FT_PARSE.H
t_node			*ft_parsefile(char *file);
unsigned int	ft_getvalue(char *str, int x);
int				ft_coord_nbr(char *str);
void			ft_insert_map(char *str, t_node **map, int cr);

// FT_MATH.H
int				direction_vector(int x1, int y1, int x2, int y2);
t_vector		rotate_direction(t_vector cl);
t_vector		trans_vectoriel(t_vector vector, int tr_x, int tr_y);
t_vector		new_vector(double x1, double y1, double x2, double y2);
t_vector		new_vector_iso(t_axe a, t_axe b);
t_vector		cpy_vector(t_vector v_out, t_vector v_in);

// FT_LIST.H
t_node			*ft_new_lstfdf(t_node *first, t_axe xyz);
t_node			*ft_lstadd_right(t_node **map, t_node *new);
void			ft_lstadd_left(t_node **line, t_node **prev, t_node *new);
void			ft_print_map(t_node *map, int x, int y);
void			ft_del_map(t_node **map);

#endif
