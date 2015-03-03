/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1quarter_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:14:04 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/07 11:42:09 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void test_opt(char *s1, t_opt *opt, char *optatest)
{
	if ((optatest[0] == 'l' && opt->opt_type == opt_l) ||
		(optatest[1] == 'l' && opt->opt_type == opt_ll) ||
		(optatest[0] == 'h' && opt->opt_type == opt_h) ||
		(optatest[1] == 'h' && opt->opt_type == opt_hh) ||
		(optatest[0] == 'j' && opt->opt_type == opt_j) ||
		(optatest[0] == 'z' && opt->opt_type == opt_z))
		return ;
	if (opt->opt_type != opt_none)
	{
		ft_putendl2_c("ft_printf : 0x110.1 Bad order of flags : ", s1, "red");
		opt->error = -1;
	}
}

char	*handle_l(char *s1, t_opt *opt)
{
	if (s1[1] == 'l')
	{
		test_opt(s1, opt, "ll");
		opt->opt_type = opt_ll;
		return (&s1[2]);
	}
//	test_opt(s1, opt, "l");
	opt->opt_type = opt_l;
	return (&s1[1]);
}

char	*handle_h(char *s1, t_opt *opt)
{
	if (s1[1] == 'h')
	{
		test_opt(s1, opt, "hh");
		opt->opt_type = opt_hh;
		return (&s1[2]);
	}
//	test_opt(s1, opt, "h");
	opt->opt_type = opt_h;
	return (&s1[1]);
}

char	*handle_j(char *s1, t_opt *opt)
{
//	test_opt(s1, opt, "j");
	opt->opt_type = opt_j;
	return (&s1[1]);
}

char	*handle_z(char *s1, t_opt *opt)
{
//	test_opt(s1, opt, "z");
	opt->opt_type = opt_z;
	return (&s1[1]);
}

