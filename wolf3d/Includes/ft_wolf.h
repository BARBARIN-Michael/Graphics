/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:21:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/30 13:14:23 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H

# include <mlx.h>
# include <libft.h>

# define WALL			"Tiles/wall.xpm"
# define FLOOR			"Tiles/snowy03.xpm"
# define DOOR			"Tiles/door.xpm"
# define MUR_BOIS		"Tiles/mur.xpm"
# define BRIQUE			"Tiles/briques.xpm"
# define REDROCK			"Tiles/redrock.xpm"
# define PLASMA			"Tiles/plasma.xpm"
# define FLAMES			"Tiles/flames.xpm"
# define WEAPON_0		"Tiles/weapon.xpm"
# define WEAPON_1		"Tiles/weapon2.xpm"
# define WEAPON_2		"Tiles/weapon3.xpm"
# define WEAPON_3		"Tiles/weapon4.xpm"
# define WEAPON_F		"Tiles/weaponfrappe.xpm"
# define TILE_Y_B		"Tiles/carreauJN.xpm"

typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long int	t_color;
typedef struct s_env		t_env;

typedef struct	s_rgb
{
	char		r;
	char		g;
	char		b;
}				t_rgb;

typedef struct	s_screen
{
	t_ushort	width;
	t_ushort	height;
}				t_screen;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_line
{
	int			start;
	int			end;
}				t_line;

typedef struct	s_movement
{
	t_coord		stape;
	t_bool		collision;
	t_bool		wall_hor;
	t_line		px;
	t_coord		texture;
}				t_move;

typedef struct	s_director
{
	double		x;
	double		y;
}				t_dir;

typedef struct	s_floor
{
	double		currentdist;
	double		weight;
	t_dir		currentfloor;
	t_coord		texture;
	t_coord		dist_player;
	int			x;
	int			y;
}				t_floor;

typedef struct	s_moving
{
	t_ushort	up		: 1;
	t_ushort	down	: 1;
	t_ushort	right	: 1;
	t_ushort	left	: 1;
}				t_moving;

typedef struct	s_distance
{
	double		x;
	double		y;
}				t_dist;

typedef struct	s_time
{
	double		time;
	double		oldtime;
}				t_time;

typedef struct	s_datagame
{
	t_dir		pos;
	t_dir		plane;
	t_dir		dir;
	t_time		time;
}				t_datagame;

typedef struct	s_datacamera
{
	double		cam_x;
	t_coord		step;
	t_dir		raypos;
	t_dir		raydir;
	t_coord		coord_map;
	t_dist		wall;
	t_dist		wall_next;
	double		lenght_wall;
	int			height_wall;
	double		wallx;
}				t_datacam;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			sizeline;
	void		*ptr;
	int			bpp;
	int			endian;
	t_screen	wh;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img[20];
	int			buffer;
}				t_mlx;

typedef struct	s_map
{
	int			**line;
	int			nbr_line;
}				t_map;

typedef void	(*t_fcts_keypad) (t_env *env, int state);
typedef void	(*t_fcts_mouse) (t_env *env, int state);

struct			s_env
{
	t_screen		wh;
	t_coord			map_max;
	t_map			*world_map;
	t_mlx			mlx;
	char			*title;
	t_datagame		*datagame;
	t_datacam		*datacam;
	double			fps;
	double			framerate;
	int				initial;
	t_moving		movement;
	char			mode;
	char			map;
	char			mapdesign;
	char			nb_px;
	char			cmp_map;
	char			anim;
	char			sens;
	char			frappe;
	t_coord			tp;
	double			speed;
	t_fcts_keypad	*fct_key;
};

/*
** ****************************************************************************
** ** ft_mlx.c
** ** mlx manager
** ****************************************************************************
*/
void			ft_init_mlx(t_env *env);
void			ft_putweapon(t_env *env);
void			ft_putimage(t_env *env, t_img *img);
void			ft_init_sprite(t_env *env);

/*
** ****************************************************************************
** ** ft_err
** ** error manager
** ****************************************************************************
*/
void			ft_error(const char *str_error, const char *name, int error);

/*
** ****************************************************************************
** ** ft_eventkey.c
** ** key manager
** **************************************************************************
*/
void			ft_updown(int val, t_env *env);
void			ft_rightleft(int val, t_env *env);
void			ft_newmode(int val, t_env *env);

/*
** ****************************************************************************
** ** ft_draw.c
** ** function that draw world
** ****************************************************************************
*/
void			ft_draw_line_v(int x, t_line line, t_env *env, t_rgb rgb);
void			ft_draw_map(int x, int y, t_env *env, t_rgb rgb);

/*
** ****************************************************************************
** ** ft_calc_draw.c
** ** function that calcul a new movement for draw a world
** ****************************************************************************
*/
void			ft_engine_rc(int x, t_env *env);
void			ft_engine_tiles_rc(int x, t_env *env);

/*
** ****************************************************************************
** ** ft_setupfcts.c
** ** initialize a array of fct ptr with different function (movement, ...)
** ****************************************************************************
*/
void			ft_setupfcts(t_fcts_keypad *keypad, t_fcts_mouse *mouse);

/*
** ****************************************************************************
** ** ft_parse.c
** ** parse file for get new map
** ****************************************************************************
*/
void			ft_parse(char *file, t_env *env);
t_coord			ft_parse_tp(t_env *e, t_coord tp1, int tp);

/*
** ****************************************************************************
** ** ft_action_key.c
** ** new action of key press
** ****************************************************************************
*/
void			ft_action_move_up(t_env *env, int state);
void			ft_action_move_down(t_env *env, int state);
void			ft_action_move_left(t_env *env, int state);
void			ft_action_move_right(t_env *env, int state);
void			ft_action_kill(t_env *env, int state);
void			ft_manage_move(t_env *env, t_move *data);

/*
** ****************************************************************************
** ** ft_action_mouse.c
** ** new action of mouse movement and press
** ****************************************************************************
*/
void			ft_action_mouse_left(int x, int y, t_env *env);
void			ft_action_mouse_right(int x, int y, t_env *env);
void			ft_action_mouse_mid(int x, int y, t_env *env);

/*
** ****************************************************************************
** ** ft_color.c
** ** color palet
** ****************************************************************************
*/
t_rgb			ft_get_color_by_pt(int map_elem, int mod, t_move data);
void			ft_color_tile(t_env *env, t_move *data, int tabi);
void			ft_color_floor(t_env *env, t_move *data, t_floor fl);

/*
** ****************************************************************************
** ** ft_event.c
** ** event call mouse and key
** ****************************************************************************
*/
int				key_press(int key, t_env *env);
int				key_release(int key, t_env *env);
int				mouse_event(int button, int x, int y, t_env *env);
int				loop_hook(t_env *env);
int				map_hook(t_env *env);

/*
** ****************************************************************************
** ** ft_exec.c
** ** primary function that execute a totaly event
** ****************************************************************************
*/
void			ft_exec(char *file, char *title, int mode, t_screen wh);
void			ft_exit(t_env *env);

/*
** ****************************************************************************
** ** ft_exec.c
** ** primary function that execute a totaly event
** ****************************************************************************
*/
void			ft_graph(t_env *env);

/*
** ****************************************************************************
** ** ft_init.c
** ** initialize all movement variable
** ****************************************************************************
*/
void			init_player_position(int x, t_env *env);
void			first_init(t_env *env);

/*
** ****************************************************************************
** ** ft_tiles.c
** ** create tiles for UI
** ****************************************************************************
*/
void			ft_draw_collumn(t_move *d, t_env *e, int x);
void			ft_draw_floor(t_move *d, t_env *e, int x);
void			ft_draw_wall(t_move *data, t_env *env, int x);
void			ft_orientation(t_move *d, t_env *e);

/*
** ****************************************************************************
** ** ft_mapdesign.c
** ** create micro world map
** ****************************************************************************
*/
void			ft_mapdesign(t_env *env);

/*
** ****************************************************************************
** ** ft_movement.c
** ** manage movement
** ****************************************************************************
*/
void			ft_movement_up(t_env *env, t_move *data);
void			ft_movement_down(t_env *env, t_move *data);
void			ft_movement_left(t_env *env);
void			ft_movement_right(t_env *env);

#endif
