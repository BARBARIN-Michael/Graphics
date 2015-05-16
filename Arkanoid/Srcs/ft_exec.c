/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 11:06:13 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/03 16:59:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arka.h>

static void		initialized(t_env *env)
{
	//env->world_map = ft_memalloc(sizeof(t_map));
	if (!glfwInit())
		F_ERR("GLFW initialisation failed", "initialized");
	if (!singleton_env())
		F_ERR("env initialisation failed", "initialized");
	ENV->world_map = ft_memalloc(sizeof(t_env));
}

static void		new_windows(t_env *env, t_screen wh, char *title)
{
	ENV->glfwin = glfwCreateWindow( wh.width, wh.height, "title", NULL, NULL); 
	if (!ENV->glfwin)
	{ 
		glfwTerminate(); 
		F_ERR("Cannot create ptr windows! Please contact useless sys-admin",
				"new_windows");
		exit(0);
	} 
	glfwMakeContextCurrent(ENV->glfwin); 
	glfwGetFramebufferSize(ENV->glfwin, &ENV->wh.width, &ENV->wh.height);
}

void			ft_exec(char *file, char *title, int mode, t_screen wh)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	initialized(NULL);
	ft_parse(file, ENV);
	ft_printf("test : %d\n", ENV->world_map->line[0][0]);
	ft_printf("test : %d\n", ENV->world_map->line[0][1]);
	ft_printf("test : %d\n", ENV->world_map->line[0][2]);
	ft_printf("test : %d\n", ENV->world_map->line[0][4]);
	ft_printf("test : %d\n", ENV->world_map->line[0][5]);
	ft_printf("test : %d\n", ENV->world_map->line[0][6]);
	ft_printf("test : %d\n", ENV->world_map->line[1][0]);
	ft_printf("test : %d\n", ENV->world_map->line[1][1]);
	ft_printf("test : %d\n", ENV->world_map->line[1][2]);
	ft_printf("test : %d\n", ENV->world_map->line[1][4]);
	ft_printf("test : %d\n", ENV->world_map->line[1][5]);
	ft_printf("test : %d\n", ENV->world_map->line[1][6]);
	exit(0);
	new_windows(ENV, wh, title);
	glfwSwapInterval(1);
	glfwSetKeyCallback(ENV->glfwin, key_callback);
	while (!glfwWindowShouldClose(ENV->glfwin))
	{
		a += 10;
		b += 10;
		glViewport(0, 0, ENV->wh.width, ENV->wh.height); 
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, wh.width, wh.width, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		rect_cursor(value_callback_x(READ, 0, *ENV));
		glPushMatrix();
		//glTranslatef(a, b, 0);
		circle_ball(ENV->wh.width / 2, ENV->wh.height / 2);
		glPopMatrix();
		//create_map(*ENV);
		glfwSwapBuffers(ENV->glfwin);
		glfwPollEvents();
	}
}
