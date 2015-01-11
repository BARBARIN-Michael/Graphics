/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:30:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/11 12:05:32 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# define TRUE = 1
# define FALSE = 0
# define WIDTH 1100
# define HEIGHT 1100
# define TITLE_WIN "FDF a la BARBARE"

#include <mlx.h>
#include <libft.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "get_next_line.h"

typedef int bool;
typedef long int color;
typedef unsigned int size_vector;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*data;
	int				height;
	int				width;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	color;
	char			*data_color;
	int				modes;
}					t_mlx;

typedef struct	s_vector
{
	int x1;
	int y1;
	int x2;
	int y2;
	int alt;
}				t_vector;

typedef struct	s_axe
{
	int x;
	int y;
	int z;
}				t_axe;

typedef struct		s_node
{
	t_axe			xyz;
	char			*col;
	struct s_node	*first_xnode;
	struct s_node	*left_node;
	struct s_node	*right_node;
}					t_node;

typedef struct	s_cline
{
	t_axe	xy;
	int		xincr;
	int		yincr;
	int		error;
	int		dx;
	int		dy;
	int		mode;
}				t_cline;

typedef struct	s_env
{
	int		w;
	int		h;
	int		dx;
	int		dy;
	int		prof;
	int		ofprof;
	t_node	*map;
	t_mlx	mlx;
}				t_env;

typedef struct	s_rgb
{
	color	r;
	color	g;
	color	b;
}				t_rgb;

// FT_FDF.H
void			ft_fdf(char *str, int w, int h, int mode);
void			exit_fdf(t_node *map, t_mlx *mlx);
void			ft_icd_mlx(t_mlx *mlx, int state, int width, int height);
int				lenght_map(t_node **map);

// FT_GRAPH.H
void			draw_pixel_to_img(int x, int y, t_rgb unitcolor, t_env *env);
void			draw_fdf(t_env *env);

// FT_ALGOFDF.H
double			coord_x_iso(int x, int y, int tilew, int tileh);
double			coord_y_iso(int x, int y, int z, int tileh, int tilew, int t_z);

// FT_PARSE.H
t_node			*ft_parsefile(char *file);
unsigned int	ft_getvalue(char *str, int x, char **col);
int				ft_coord_nbr(char *str);
void			ft_insert_map(char *str, t_node **map, int cr);

// FT_MATH.H
int				correct_vector(t_vector *vec1);
t_vector		*rotate_direction(t_vector *cl);
t_vector		trans_vectoriel(t_vector vector, int tr_x, int tr_y);
t_vector		new_vector(t_axe a, t_axe b);
t_vector		new_vector_iso(t_axe a, t_axe b, int vec_w, int vec_h, int v_z);
t_vector		cpy_vector(t_vector v_out, t_vector v_in);
int				abs(int val);

// FT_LIST.H
t_node			*ft_new_lstfdf(t_node **map, t_axe xyz, char *col);
t_node			*ft_lstadd_right(t_node **map, t_node *new);
void			ft_lstadd_left(t_node **line, t_node **prev, t_node *new);

// FT_MAP.H
void			ft_del_map(t_node **map);
int				*ft_map_height(t_node **map);

// FT_MATHLINE.H
void			draw_line1(t_vector v1, t_env *env, char *col, char *offcol);

// FT_EVENT.H
int				ft_event_key(int key, t_env *env);
int				ft_event_expose(t_env *env);

// FT_COLOR.H
t_rgb			getcolorbydegrade(char **color, int delta, int idelta);
t_rgb			getcolormap(int height, t_node **map);
t_rgb			getshaded(t_rgb rgb1, t_rgb rgb2, int delta, int idelat);
t_rgb			create_rgb(char *col);
#endif
