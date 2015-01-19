/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:30:10 by mbarbari          #+#    #+#             */
/*   Updated: 2015/01/19 13:31:45 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <mlx.h>
# include <libft.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "get_next_line.h"
# define dround(x) (int)((x) > 0 ? (x) + 0.5 : (x) - 0.5)
# define TRUE 1
# define FALSE 0
# define WIDTH 55
# define HEIGHT 45
# define TITLE_WIN "FDF a la BARBARE"

typedef int				t_bool;
typedef long int		t_color;
typedef unsigned int	t_size_vector;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	color;
	char			*data_color;
	int				modes;
}					t_mlx;

typedef struct		s_vector
{
	int x1;
	int y1;
	int x2;
	int y2;
	int alt;
}					t_vector;

typedef struct		s_axe
{
	int x;
	int y;
	int z;
}					t_axe;

typedef struct		s_node
{
	int				*tabz;
	char			**col;
	struct s_node	*next;
	int				elem;
}					t_node;

typedef struct		s_cline
{
	t_axe	xy;
	int		xincr;
	int		yincr;
	int		error;
	int		dx;
	int		dy;
	int		h;
	int		i;
	int		mode;
}					t_cline;

typedef struct		s_env
{
	int		w;
	int		h;
	int		dx;
	int		dy;
	int		prof;
	int		ofprof;
	int		height;
	int		width;
	t_node	*map;
	int		proj;
	t_mlx	mlx;
}					t_env;

typedef struct		s_rgb
{
	t_color	r;
	t_color	g;
	t_color	b;
}					t_rgb;

void				ft_fdf(char *str, int w, int h, int mode);
void				exit_fdf(t_node *map, t_mlx *mlx);
void				ft_icd_mlx(t_env *env, int state);
int					lenght_x_map(t_node **map);
int					lenght_y_map(t_node **map);
void				draw_pixel_to_img(int x, int y, t_rgb color, t_env *env);
void				draw_fdf(t_env *env);
int					coord_x_iso(t_axe xy, int tilew, int tileh);
int					coord_y_iso(t_axe xyz, int tileh, int tilew, int t_z);
double				coord_y_par(t_axe xyz, int tileh, int tilew, int t_z);
double				coord_x_par(t_axe xyz, int tileh, int tilew, int t_z);
t_node				*ft_parsefile(char *file);
unsigned int		ft_getvalue(char *str, int x, char **col);
int					ft_coord_nbr(char *str);
void				ft_insert_map(char *str, t_node **map, int x, int y);
t_vector			trans_vectoriel(t_vector vector, int tr_x, int tr_y);
t_vector			new_vector_plane(t_axe a, t_axe b, t_env *env);
t_vector			new_vector_iso(t_axe a, t_axe b, t_env *env);
t_vector			new_vector_par(t_axe a, t_axe b, t_env *env);
t_node				*ft_lstadd_right(t_node **map, t_node *newt);
t_node				*ft_new_lstfdf(t_node **map, int *tabz, char **col, int);
void				ft_del_map(t_node **map);
int					*ft_map_height(t_node **map);
void				draw_line1(t_vector v1, t_env *env, char *col, char *ofcol);
int					ft_event_key(int key, t_env *env);
int					ft_event_expose(t_env *env);
t_rgb				getcolorbydegrade(char **color, int delta, int idelta);
t_rgb				getcolormap(double height, t_node **map);
t_rgb				getcolormap2(double height);
t_rgb				getshaded(t_rgb rgb1, t_rgb rgb2, double percent);
t_rgb				create_rgb(char *col);
int					ft_win_lenghtw(int cmp_node);
int					ft_win_lenghth(int cmp_node);

#endif
