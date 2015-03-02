




#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>

# define ARROW_UP		65000
# define ARROW_DOWN		65000
# define ARROW_RIGHT	65000
# define ARROW_LEFT		65000
# define MOUSSE_UP		65000
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
	void	*img_tmp;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_mlx;

typedef struct	s_env
{
	t_lenght		width;
	t_lenght		height;
	t_smallint		set;
	t_mlx			mlx;
	char			*title;
}				t_env;

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
	t_ushort	iterate;
	t_ushort	zoom;
	t_area		area;
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

typedef void (*t_fcts_fractal) (const t_fract fract, t_env *env);

t_fcts_fractal *fcts_fract;

void	ft_exit(t_mlx *mlx);
void	ft_icd_mlx(t_env *env, const char *state);
void	ft_exec(char *title, int width, int height, const char *fractal);
void	ft_draw_pixel(int x, int y, t_rgb col, t_env *env);
t_rgb	ft_create_rgb(char *col);
void	ft_mandelbrot(const t_fract fract, t_env *env);
void	ft_event_mouse(int key, t_env *env);
int		ft_event_expose(t_env *env);

#endif
