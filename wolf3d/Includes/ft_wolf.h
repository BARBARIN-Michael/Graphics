/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:21:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 18:39:53 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H

#define FALSE 0
#define TRUE !0

typedef unsigned short t_ushort;
typedef unsigned int t_uint;
typedef unsigned long int t_color;
typedef unsigned long int t_map;

typedef enum
{
	TRUE,
	FALSE
}		e_bool;

typedef struct	s_rgb
{
	char		r;
	char		g;
	char		b;
}				t_rgb;

typedef struct	s_coord
{
	t_uint		x;
	t_uint		y;
}				t_coord;

typedef struct	s_line
{
	int			start;
	int			end;
}				t_line;

typedef struct	s_movement
{
	t_coord		stape;
	e_bool		collision;
	e_bool		wall_hor;
	t_line		px;
}				t_move;

typedef struct	s_director
{
	t_uint		x;
	t_uint		y;
}				t_dir;

typedef struct	s_distance
{
	t_uint		x;
	t_uint		y;
}				t_dist;

typedef struct	s_time
{
	t_uint		time;
	t_uint		oldtime;
}				t_time;

typedef struct	s_datagame
{
	t_coord		pos;
	t_coord		plane;
	t_dir		dir;
	t_time	
}				t_datagame;

typedef struct	s_datacamera
{
	int			cam_x;
	t_coord		raypos;
	t_dir		raydir;
	t_coord		coord_map;
	t_dist		wall;
	t_dist		wall_next;
	t_uint		lenght_wall;
	t_uint		height_wall;
}				t_datacam;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*data;
	int			bpp;
	int			endian;
	int			sizeline;
}				t_mlx;

typedef struct	s_env
{
	t_ushort	width;
	t_ushort	height;
	t_map		**world_map;
	t_mlx		mlx;
	char		*title;
    t_datagame	datagame;
	t_datacam	datacam;
}				t_env;

typedef void	(*t_fcts_keypad) (int val, t_env *env);
typedef void	(*t_fcts_mouse) (int val, t_env *env);

/* ****************************************************************************
** ** ft_mlx.c
** ** mlx manager
** ***************************************************************************/
void		ft_init_mlx(t_env *env);
void		ft_putimage(t_env *env);
void		ft_newcalcul(t_env *env);


/* ****************************************************************************
** ** ft_err
** ** error manager
** ***************************************************************************/
void		ft_error(const char *str_error, const char *name_log, int error);


/* ****************************************************************************
** ** ft_eventkey.c
** ** key manager
** ***************************************************************************/
void		ft_updown(int val, t_env *env);
void		ft_rightleft(int val, t_env *env);
void		ft_newmode(int val, t_env *env);


/* ****************************************************************************
** ** ft_draw.c
** ** function that draw world
** ***************************************************************************/
void		ft_draw_line_v(int x, t_line line, t_env *env, t_rgb rgb);

/* ****************************************************************************
** ** ft_movement.c
** ** function that calcul a new movement for draw a world
** ***************************************************************************/
void		ft_new_calc_movement(t_env *env);

#endif
