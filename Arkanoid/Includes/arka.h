/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arka.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 10:58:31 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/03 15:10:54 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKA_H
# define ARKA_H

# define GLFW_INCLUDE_GLU
# include <glfw3.h>
# include <ft_printf.h>
# include <ft_checking.h>

# define WIDTH_CURSOR1	300
# define HEIGHT_CURSOR1	900
# define WIDTH_CURSOR2	380
# define HEIGHT_CURSOR2	920

# define ENV			singleton_env()

# define WIDTH_BLOCK1	
# define READ			1
# define WRITE			0

typedef struct	s_env	t_env;

typedef struct  s_screen
{
	int    width;
	int    height;
}               t_screen;

typedef struct	s_rgb
{
	t_ushort	r;
	t_ushort	g;
	t_ushort	b;
}				t_rgb;

typedef struct	s_coord4f
{
	float		pt_hl_x;
	float		pt_hl_y;
	float		pt_lr_x;
	float		pt_lr_y;
}				t_coord4f;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_elem
{
	int			x;
	int			y;
}				t_elem;

typedef struct	s_map
{
	int			**line;
	int			nbr_line;
}				t_map;

struct			s_env
{
	t_screen		wh_data;
	t_screen		wh;
	t_map			*world_map;
	t_elem			map_max;
	GLFWwindow		*glfwin;
};

void		ft_exec(char *file, char *title, int mode, t_screen wh);
void		key_callback(GLFWwindow *win, int key, int scan, int act, int mod);
float		value_callback_x(int read, float newx, t_env env);
void		rect_cursor(int x1);
void		circle_ball(int cx, int cy);
void		ft_parse(char *filename, t_env *env);
void		create_map(t_env env);
t_env		*singleton_env(void);

#endif
