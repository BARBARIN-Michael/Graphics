/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2quarter_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:29:42 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/12 12:19:06 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*handle_0(char *s1, t_opt *opt)
{
	opt->opt_0 = 1;
	if (opt->opt_base > opt->opt_0)
	{
		ft_putendl2_c("ft_printf : Bad order of flags ", s1, "red");
		exit(-1);
	}
	opt->opt_base = opt->opt_base & opt->opt_0;
	if (opt->opt_neg == 1)
		opt->opt_0 = 0;
	return (&s1[1]);
}

char	*handle_sharp(char *s1, t_opt *opt)
{
	opt->opt_sharp = 1;
	if (opt->opt_base > opt->opt_sharp)
	{
		ft_putendl2_c("ft_printf : Bad order of flags ", s1, "red");
		exit(-1);
	}
	opt->opt_base = opt->opt_base & opt->opt_sharp;
	return (&s1[1]);
}
