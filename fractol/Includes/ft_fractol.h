/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 10:54:24 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/02 18:59:43 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>

# define ARROW_UP		65362
# define ARROW_DOWN		65364
# define ARROW_RIGHT	65363
# define ARROW_LEFT		65361
# define MOUSSE_UP		65
# define MOUSSE_DOWN	65000
# define KEY_ESCAPE		65307

# define X1				-2.100000
# define X2				0.600000
# define Y1				-1.200000
# define Y2				1.200000

typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef long int		t_color;
typedef t_ushort		t_lenght;
typedef t_ushort		t_smallint;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*data;
	void	*img_tmp;
	char	*data_tmp;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_mlx;

typedef struct	s_coord
{
	double x;
	double y;
}				t_coord;

typedef struct	s_area
{
	t_coord xy1;
	t_coord xy2;
}				t_area;

typedef struct	s_fract
{
	t_uint		iterate;
	t_uint		zoom;
	t_area		area;
	double		cst_zoom;
}				t_fract;

typedef struct	s_complex
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
}				t_complex;

typedef struct	s_rgb
{
	t_color	r;
	t_color	g;
	t_color	b;
}				t_rgb;

typedef struct s_env	t_env;

typedef void	(*t_fcts_fractal) (const t_fract fract, t_env *env);

struct			s_env
{
	t_lenght		width;
	t_lenght		height;
	t_smallint		set;
	t_mlx			mlx;
	char			*title;
	t_fract			fract;
	t_fcts_fractal	fcts;
	t_bool			affichage;
};

void			ft_exit(t_mlx *mlx);
void			ft_icd_mlx(t_env *env, const char *state);
void			ft_exec(char *title, int width, int height, const char *fra);
void			ft_draw_pixel(int x, int y, t_rgb col, t_env *env);
t_rgb			ft_create_rgb(char *col);
void			ft_mandelbrot(t_fract fract, t_env *env);
int				ft_event_mouse(int button, int x, int y, t_env *env);
int				ft_event_key(int key, t_env *env);
int				ft_event_expose(t_env *env);
void			ft_zoom_mandelbrot(int x, int y, t_env *env);
void			ft_move_mandelbrot(int key, t_env *env);
int				ft_event_fractal(t_env *env);

#endif
