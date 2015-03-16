/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:54:27 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 01:45:29 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

void	ft_action_move_up(t_env *env, int state)
{
	env->movement.up = state;
}

void	ft_action_move_down(t_env *env, int state)
{
	env->movement.down = state;
}

void	ft_action_move_left(t_env *env, int state)
{
	env->movement.left = state;
}

void	ft_action_move_right(t_env *env, int state)
{
	env->movement.right = state;
}

void	ft_manage_move(t_env *env)
{
	if (env->movement.up)
		ft_movement_up(env);
	if (env->movement.left)
		ft_movement_left(env);
	if (env->movement.right)
		ft_movement_right(env);
	if (env->movement.down)
		ft_movement_down(env);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:47:30 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 01:45:58 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

void	ft_action_mouse_left(int x, int y, t_env *env)
{
	return ;
}

void	ft_action_mouse_right(int x, int y, t_env *env)
{
	return ;
}

void	ft_action_mouse_mid(int x, int y, t_env *env)
{
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 16:39:47 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 01:56:46 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static t_rgb	ft_setup_color(t_ushort type_color)
{
	t_rgb	rgb[17];
	//Nord
	rgb[0] = (t_rgb) {0x57, 0x2B, 0x06};
	rgb[1] = (t_rgb) {.r = 0x70, .g = 0x38, .b = 0x08};
	rgb[2] = (t_rgb) {.r = 0xA6, .g = 0x53, .b = 0x0C};
	rgb[3] = (t_rgb) {.r = 0xD6, .g = 0xA7, .b = 0x1D};
	//Sud
	rgb[4] = (t_rgb) {.r = 0x57, .g = 0x2B, .b = 0x06};
	rgb[5] = (t_rgb) {.r = 0xD6, .g = 0x8D, .b = 0x1D};
	rgb[6] = (t_rgb) {.r = 0xA0, .g = 0x8D, .b = 0x1D};
	rgb[7] = (t_rgb) {.r = 0x69, .g = 0x8D, .b = 0x1D};
	//Est
	rgb[8] = (t_rgb) {.r = 0xB8, .g = 0x94, .b = 0x88};
	rgb[9] = (t_rgb) {.r = 0x8A, .g = 0x94, .b = 0x88};
	rgb[10] = (t_rgb) {.r = 0x5A, .g = 0x94, .b = 0x88};
	rgb[11] = (t_rgb) {.r = 0x07, .g = 0x94, .b = 0x88};
	//OUEST
	rgb[12] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x1C};
	rgb[13] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x3F};
	rgb[14] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0x63};
	rgb[15] = (t_rgb) {.r = 0x8F, .g = 0x24, .b = 0xA8};
	//Defaut
	if (type_color > 15)
		type_color = 16;
	rgb[16] = (t_rgb) {.r = 0xFF, .g = 0xFF, .b = 0xFF};
	return (rgb[type_color]);
}

t_rgb			ft_get_color_by_pt(int map_elem, int mod)
{
	t_rgb rgb;

	rgb = ft_setup_color(map_elem);
	rgb = (t_rgb) {.r = rgb.r / mod, .g = rgb.g / mod, .b = rgb.b / mod};
	return (rgb);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                      :+:      :+:    :+:   	  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:32:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/06 19:37:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

void	ft_draw_line_v(int x, t_line line, t_env *env, t_rgb rgb)
{
	int		tabi;

	while (line.start <= line.end)
	{
		if (line.start >= (env->wh.height - 1) || x >= (env->wh.width - 1))
			break ;
		tabi = ((line.start * env->mlx.sizeline) + (x * (env->mlx.bpp / 8)));
		env->mlx.data[tabi] = rgb.b;
		env->mlx.data[tabi + 1] = rgb.g;
		env->mlx.data[tabi + 2] = rgb.r;
		line.start++;
	}
}

void	ft_draw_px(int x, int y, t_env *env, t_rgb rgb)
{
	int tabi;

	tabi = (y * env->mlx.sizeline + x * (env->mlx.bpp / 8));
	env->mlx.data[tabi] = rgb.b;
	env->mlx.data[tabi + 1] = rgb.g;
	env->mlx.data[tabi + 2] = rgb.r;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 23:35:56 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:12:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <def.h>
#include <math.h>

static void	calc_movex(t_move *data, t_env *env, int mod)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	if (mod == 0)
	{
		data->stape.x = -1;
		cam->wall.x = (cam->raypos.x - cam->coord_map.x) * cam->wall_next.x;
	}
	else if (mod == 1)
	{
		data->stape.x = 1;
		cam->wall.x = (cam->coord_map.x + 1.0 - cam->raypos.x) * cam->wall_next.x;
	}
}

static void	calc_movey(t_move *data, t_env *env, int mod)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	if (mod == 0)
	{
		data->stape.y = -1;
		cam->wall.y = (cam->raypos.y - cam->coord_map.y) * cam->wall_next.y;
	}
	else if (mod == 1)
	{
		data->stape.y = 1;
		cam->wall.y = (cam->coord_map.y + 1.0 - cam->raypos.y) * cam->wall_next.y;
	}
}

static void calc_collision(t_move *data, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	while (data->collision == FALSE)
	{
		if (cam->wall.x < cam->wall.y)
		{
			cam->wall.x += cam->wall_next.x;
			cam->coord_map.x += data->stape.x;
			data->wall_hor = FALSE;
		}
		else
		{
			cam->wall.y += cam->wall_next.y;
			cam->coord_map.y += data->stape.y;
			data->wall_hor = TRUE;
		}
		if (env->world_map->line[cam->coord_map.x][cam->coord_map.y] > 0)
			data->collision = TRUE;
	}
}

static void	calc_sweep(t_move *data, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	if (data->wall_hor == FALSE)
		cam->lenght_wall = fabs((cam->coord_map.x - cam->raypos.x + (1 - data->stape.x) / 2) / cam->raydir.x);
	else
		cam->lenght_wall = fabs((cam->coord_map.y - cam->raypos.y + (1 - data->stape.y) / 2) / cam->raydir.y);
	cam->height_wall = abs((int)(env->wh.height / cam->lenght_wall));
}

void		ft_engine_rc(int x, t_env *env)
{
	t_move		data;
	t_datacam	*cam;
	t_datagame	*game;
	t_rgb		rgb;

	cam = env->datacam;
	game = env->datagame;
	
	init_player_position(x, env);
	data = (t_move) {	.stape = 0, .collision = FALSE, .wall_hor = FALSE,
						.px.start = 0, .px.end = 0};
	cam->raydir.x < 0 ? calc_movex(&data, env, 0) : calc_movex(&data, env, 1);
	cam->raydir.y < 0 ? calc_movey(&data, env, 0) : calc_movey(&data, env, 1);
	calc_collision(&data, env);
	calc_sweep(&data, env);
	data.px.start = -cam->height_wall / 2 + env->wh.height / 2;
	data.px.start = data.px.start < 0 ? 0 : data.px.start;
	data.px.end = cam->height_wall / 2 + env->wh.height / 2;
	data.px.end = data.px.end >= env->wh.height ? env->wh.height - 1 : data.px.end;
	rgb = ft_get_color_by_pt(
	env->world_map->line[cam->coord_map.x][cam->coord_map.y],
	(data.wall_hor == TRUE ? 2 : 1));
	printf(C_BROWN"Coordonnee : line.start = %d"C_NONE"\n", data.px.start);
	ft_draw_line_v(x, (t_line) {0, data.px.start}, env, (t_rgb){120, 120, 120});
	printf(C_BROWN"Coordonnee : line.start = %d"C_NONE"\n", data.px.start);
	ft_draw_line_v(x, data.px, env, rgb);
	printf(C_BROWN"Coordonnee : line.start = %d"C_NONE"\n", data.px.start);
	ft_draw_line_v(x, (t_line) {data.px.end, env->wh.height}, env, (t_rgb){0xAF, 0xFA, 0xAF});
	printf(C_BROWN"Coordonnee : line.start = %d"C_NONE"\n", data.px.end);
	ft_manage_move(env);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:51:19 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 04:41:35 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_error(const char *str_error,const char *name_log, int error_type)
{
	if (error_type > 1)
	{
		ft_putstr(C_RED"FATAL ERROR ["C_NONE);
		ft_putstr(str_error);
		ft_putstr(C_RED"] : "C_NONE);
		ft_putendl(name_log);
		exit (error_type);
	}
	else
	{
		ft_putstr(C_RED"ERROR ["C_NONE);
		ft_putstr(str_error);
		ft_putstr(C_RED"] : "C_NONE);
		ft_putendl(name_log);
		return ;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:01:29 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 06:51:38 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_event.h>
#include <ft_wolf.h>

int		mouse_event(int button, int x, int y, t_env *env)
{
	if (button == MOUSE_BT_LEFT)
		ft_action_mouse_left(x, y, env);
	else if (button == MOUSE_BT_RIGHT)
		ft_action_mouse_right(x, y, env);
	else if (button == MOUSE_BT_MID)
		ft_action_mouse_mid(x, y, env);
}

int		key_press(int key, t_env *env)
{
	if (key == KEY_W)
		ft_action_move_up(env, 1);
	else if (key == KEY_S)
		ft_action_move_down(env, 1);
	else if (key == KEY_A)
		ft_action_move_right(env, 1);
	else if (key == KEY_D)
		ft_action_move_left(env, 1);
	else if (key == KEY_1)
		ft_print_map(env);
	else if (key == KEY_ESCAPE)
		ft_exit(env);
}

int		key_release(int key, t_env *env)
{
	if (key == KEY_W)
		ft_action_move_up(env, 0);
	else if (key == KEY_S)
		ft_action_move_down(env, 0);
	else if (key == KEY_A)
		ft_action_move_right(env, 0);
	else if (key == KEY_D)
		ft_action_move_left(env, 0);
}

int		loop_hook(t_env *env)
{
	int		x;
	static int test = 0;

	x = 0;
	//return (0);
	if (	env->initial == 0 && !env->movement.up && !env->movement.down &&
			!env->movement.left && !env->movement.right)
			return (0);
	env->initial = 0;
	ft_bzero(env->mlx.data, env->mlx.sizeline * env->wh.height);
	while (x <= env->wh.width)
	{
		ft_engine_rc(x, env);
		x++;
	}
	ft_graph(env);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:45:03 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:07:49 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <libft.h>

void		ft_exit(t_env *env)
{
	mlx_destroy_image(env->mlx.mlx_ptr, env->mlx.img);
	mlx_destroy_window(env->mlx.mlx_ptr, env->mlx.win_ptr);
	free(env->datagame);
	free(env->datacam);
	free(env->world_map);
	exit(0);
}

void		ft_exec(char *file, char *title, int mode, t_screen wh)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	env = (t_env) {.wh = wh, .title = title, .mode = mode, .initial = 1};
	env.world_map = malloc(sizeof(t_map));
	env.datagame = malloc(sizeof(t_datagame));
	env.datacam = malloc(sizeof(t_datacam));
	ft_init_mlx(&env);
	ft_setupfcts(env.fct_key, (void *)0);
	first_init(&env);
	ft_parse(file, &env);
	loop_hook(&env);
	env.initial = 0;
	mlx_hook(env.mlx.win_ptr, KeyPress, KeyPressMask, &key_press, &env);
	mlx_hook(env.mlx.win_ptr, KeyRelease, KeyReleaseMask, &key_release, &env);
	mlx_loop_hook(env.mlx.mlx_ptr, &loop_hook, &env);
	mlx_loop(env.mlx.mlx_ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:12 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:01:16 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <time.h>

void	ft_graph(t_env *env)
{
	struct timeval timeval;

	env->datagame->time.oldtime = env->datagame->time.time;
	gettimeofday(&timeval, NULL);
	env->datagame->time.time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000.0;
	env->framerate = (env->datagame->time.time - env->datagame->time.oldtime) / 1000.0;
	env->fps = 1.0 / env->framerate;
	ft_putimage(env, env->mlx.img);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:56:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:00:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <libft.h>
#include <def.h>
#include <math.h>

void		first_init(t_env *env)
{
	env->datagame->pos = (t_dir) {.x = 3.0, .y = 3.0};
	env->datagame->dir = (t_dir) {.x = -1.0, .y = 0.0};
	env->datagame->plane = (t_dir) {.x = 0.0, .y = 0.66};
	env->datagame->time = (t_time) {.time = 0.0, .oldtime = 0.0};
	env->fps = 0;
}

static double ft_sqrt(double x)
{
	return (x * x);
}

void		init_player_position(int x, t_env *env)
{
	t_datacam	*cam;
	t_datagame	*game;

	cam = env->datacam;
	game = env->datagame;
	cam->cam_x = 2 * x  / (double)(env->wh.width) - 1;
	cam->raypos.x = game->pos.x;
	cam->raypos.y = game->pos.y;
	cam->raydir.x = game->dir.x + game->plane.x * cam->cam_x;
	cam->raydir.y = game->dir.y + game->plane.y * cam->cam_x;
	cam->coord_map.x = (int)(cam->raypos.x);
	cam->coord_map.y = (int)(cam->raypos.x);
	cam->wall.x = 0;
	cam->wall.y = 0;
	cam->wall_next.x = sqrt(1 + SQRT(cam->raydir.y) / SQRT(cam->raydir.x));
	//cam->wall_next.x = sqrt(1 + (cam->raydir.y * cam->raydir.y) / (cam->raydir.x * cam->raydir.x));
	cam->wall_next.y = sqrt(1 + SQRT(cam->raydir.x) / SQRT(cam->raydir.y));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 02:10:05 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <mlx.h>

void	ft_init_mlx(t_env *env)
{
	t_screen wh;

	wh = env->wh;
	if (!(env->mlx.mlx_ptr = mlx_init()))
		ft_error("MLX cannot initialized", "init X10.1", 1);
	env->mlx.img = mlx_new_image(env->mlx.mlx_ptr, wh.width, wh.height);
	env->mlx.img_tmp = mlx_new_image(env->mlx.mlx_ptr, wh.width, wh.height);
	env->mlx.win_ptr = mlx_new_window(env->mlx.mlx_ptr, wh.width, wh.height,
			env->title);
	env->mlx.data = mlx_get_data_addr(env->mlx.img, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
	env->mlx.data_tmp = mlx_get_data_addr(env->mlx.img_tmp, &env->mlx.bpp,
			&env->mlx.sizeline, &env->mlx.endian);
}

void	ft_putimage(t_env *env, void *img)
{
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.win_ptr, img,
			0, 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:13:17 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:01:01 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <math.h>

void	ft_movement_up(t_env *env)
{
	t_coord new;
	double move_speed;

	move_speed = 0.08;
	new.x = (int)(env->datagame->pos.x + env->datagame->dir.x * move_speed);
	new.y = (int)(env->datagame->pos.y + env->datagame->dir.y * move_speed);
	if(env->world_map->line[new.x][(int)(env->datagame->pos.y)] == FALSE)
		env->datagame->pos.x += env->datagame->dir.x * move_speed ;
	else if(env->world_map->line[(int)(env->datagame->pos.x)][new.y] == FALSE)
		env->datagame->pos.y += env->datagame->dir.y * move_speed;
	env->movement.up = FALSE;
}

void	ft_movement_down(t_env *env)
{
	t_coord new;
	double move_speed;

	move_speed = 0.08;
	new.x = (int)(env->datagame->pos.x - env->datagame->dir.x * move_speed);
	new.y = (int)(env->datagame->pos.y - env->datagame->dir.y * move_speed);
	if(env->world_map->line[new.x][(int)(env->datagame->pos.y)] == FALSE)
		env->datagame->pos.x -= env->datagame->dir.x * move_speed;
	else if(env->world_map->line[(int)(env->datagame->pos.x)][new.y] == FALSE)
		env->datagame->pos.y -= env->datagame->dir.y * move_speed;
	env->movement.down = FALSE;
}

void	ft_movement_right(t_env *env)
{
	t_datagame	*game;
	double	old_dir_x;
	double	old_plan_x;
	double	rad_speed;

	//ft_bzero(env->mlx.data, env->mlx.sizeline * env->wh.height);
	rad_speed = env->framerate * 3.0;
	rad_speed = 0.03;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	game->dir.x = game->dir.x * cos(-rad_speed) - game->dir.y * sin(-rad_speed);
	game->dir.y = old_dir_x * sin(-rad_speed) + game->dir.y * cos(-rad_speed);
	game->plane.x = game->plane.x * cos(-rad_speed) - game->plane.y * sin(-rad_speed);
	game->plane.y = old_plan_x * sin(-rad_speed) + game->plane.y * cos(-rad_speed);
	env->movement.right = FALSE;
}

void	ft_movement_left	(t_env *env)
{
	t_datagame	*game;
	double	old_dir_x;
	double	old_plan_x;
	double	rad_speed;

	//ft_bzero(env->mlx.data, env->mlx.sizeline * env->wh.height);
	rad_speed = env->framerate * 3.0;
	rad_speed = 0.03;
	game = env->datagame;
	old_dir_x = game->dir.x;
	old_plan_x = game->plane.x;
	game->dir.x = game->dir.x * cos(rad_speed) - game->dir.y * sin(rad_speed);
	game->dir.y = old_dir_x * sin(rad_speed) + game->dir.y * cos(rad_speed);
	game->plane.x = game->plane.x * cos(rad_speed) - game->plane.y * sin(rad_speed);
	game->plane.y = old_plan_x * sin(rad_speed) + game->plane.y * cos(rad_speed);
	env->movement.left = FALSE;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:00:48 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 07:16:13 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <ft_wolf.h>
#include <get_next_line.h>

static int		get_line(char *str)
{
	int			nbr_line;

	nbr_line = get_nbr_line(str);
	return (nbr_line);
}

static void		ft_insert_map(char *str, t_coord xy, t_env *env)
{
	static int		**map = NULL;
	int				*line;
	int				cmp;
	char			**str_split;

	cmp = -1;
	if (!map)
	{
		if (!(map = (int **)malloc(sizeof(int *) * env->world_map->nbr_line)))
			ft_error("Allocate : memory full", "ERROR X01.1:insert_map", 1);
		env->world_map->line = map;
	}
	if (!(line = (int *)malloc(sizeof(int *) * (xy.x + 1))))
		ft_error("Cannot allocate : memory full", "ERROR X01.1:insert_line", 1);
	str_split = ft_nstrsplit(str, ',', xy.x);
	while (++cmp < xy.x)
		line[cmp] = ft_atoi(str_split[cmp]);
	map[xy.y] = line;
}

void			ft_parse(char *filename, t_env *env)
{
	int			fd;
	int			rslt;
	char		*str;
	t_coord		xy;

	if ((env->world_map->nbr_line = get_line(filename)) < 0)
		ft_error("Cannot open file", "ERROR X01.0:Parser:", 1);
	fd = open(filename, O_RDONLY);
	xy = (t_coord) {.x = 0, .y = 0};
	printf(C_RED"La map : \n");
	while ((rslt = get_next_line(fd, &str)) > 0)
	{
		if (!str[0])
			continue ;
		xy.x = ft_count_split(str, ',');
		ft_insert_map(str, xy, env);
		xy.y++;
		ft_strdel(&str);
	}
	close(fd);
	rslt < 0 ? ft_error("Cannot open file", "ERROR X01.0:Parser:", 1), 1 : 0;
}

void			ft_print_map(t_env *env)
{
	int		cmpY;
	int		cmpX;
	char	copy;

	cmpY = 0;
	cmpX = 0;
	printf(C_CYAN"====== AFFICHAGE DE LA MAP ====="C_BROWN"\n");
	while (1)
	{
		if (env->world_map->line[cmpY][cmpX] == 8 && cmpX == 0 && cmpY != 0)
			break ;
		else if (env->world_map->line[cmpY][cmpX] == 8)
		{
			write(1, "\n", 1);
			cmpX = 0;
			cmpY++;
		}
		else
		{
			copy = '0' + env->world_map->line[cmpY][cmpX];
			if (cmpX == (int)env->datagame->pos.x && cmpY == (int)env->datagame->pos.y)
			{
				ft_putstr(C_CYAN"T "C_BROWN);
			}
			else
			{
				write(1, &copy, 1);
				write(1, " ", 1);
			}
			cmpX++;
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupfcts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 12:11:18 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 04:43:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>

static void	init_fcts(t_fcts_keypad *keypad, t_fcts_mouse *mouse)
{
	int		cmp;

	cmp = 0;
	while (cmp < sizeof(char))
	{
		if (keypad)
			keypad[cmp] = (void *)0;
		if (mouse)
			mouse[cmp] = (void *)0;
		cmp++;
	}
}

static void	setup_keypad(t_fcts_keypad *keypad)
{
	keypad['w'] = &ft_action_move_up;
	keypad['s'] = &ft_action_move_down;
	keypad['a'] = &ft_action_move_left;
	keypad['d'] = &ft_action_move_right;
	//keypad['m'] = &ft_newmode;
}

static void	setup_mouse(t_fcts_mouse *mouse)
{
	return ;
}

void		ft_setupfcts(t_fcts_keypad *keypad, t_fcts_mouse *mouse)
{
	init_fcts(keypad, mouse);
	if (keypad)
		setup_keypad(keypad);
	if (mouse)
		setup_mouse(mouse);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 20:01:08 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/03 20:01:10 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <stdlib.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:40:50 by mbarbari          #+#    #+#             */
/*   Updated: 2015/03/12 05:10:10 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_wolf.h>
#include <ft_printf.h>

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_exec("../wolf.42", "Wolf 3D example map", 0, (t_screen) {800, 600});
	else if (argc == 2)
		ft_exec(argv[1], argv[1], 1, (t_screen) {800, 600});
	else
		ft_putstr("Veuillez saisir aucun parametre ou bien le fichier map\n");
	return (0);
}
