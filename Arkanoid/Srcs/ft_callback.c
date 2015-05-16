/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_callback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:59:36 by mbarbari          #+#    #+#             */
/*   Updated: 2015/05/03 15:04:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arka.h>

t_env		*singleton_env(void)
{
	static t_env	s_env;

	return (&s_env);
}

float		value_callback_x(int rw, float newx, t_env env)
{
	static float new_x = 0.0;

	if (rw == WRITE)
	{
		new_x += newx;
		if ((WIDTH_CURSOR1 + new_x) <= 7)
			new_x = 10 - WIDTH_CURSOR1;
		else if ((WIDTH_CURSOR2 + new_x) >= (ENV->wh.width - 7))
			new_x = ENV->wh.width - 7 - WIDTH_CURSOR2;
		ft_printf("Lecture : %d\n", ENV->wh.width);
	}
	else if (rw == READ)
		return (new_x);
	return (0);
}

void		key_callback(GLFWwindow *win, int key, int scan, int act, int mods)
{
	t_env	*env;

	if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(win, GL_TRUE);
		glfwTerminate();
		exit(0);
	}
	if (key == GLFW_KEY_RIGHT && (act == GLFW_REPEAT || act == GLFW_PRESS))
		value_callback_x(WRITE, 10, *ENV);
	if (key == GLFW_KEY_LEFT && (act == GLFW_REPEAT || act == GLFW_PRESS))
		value_callback_x(WRITE, -10, *ENV);
}
