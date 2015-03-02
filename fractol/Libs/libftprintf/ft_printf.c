/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:43:14 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/13 15:19:14 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <unistd.h>


static t_opt	process_flag(t_var *v, fcts_flag *fcts)
{
	t_opt	opt;
	char	*str;

	ft_bzero(&opt, sizeof(opt));
	str = v->s1;
	v->s1++;
	while (*v->s1)
	{
		v->s1 = fcts[*v->s1] != NULL ? fcts[*v->s1](v->s1, &opt) : v->s1;
		if (ft_isdigit(*v->s1) && opt.opt_dot != 1 && *v->s1 != '0')
			v->s1 = handle_lenght(v->s1, &opt);
		if (ft_strchr(OPT_FLAG, *v->s1))
			continue ;
		opt.process_invalide = (!ft_strchr(OPT_CONV, *v->s1)
				|| !*v->s1) ? 1 : 0;
		v->str_opt = ft_strsub(str, 0, (v->s1 - str) + 1);
		return (opt.type_conv = *v->s1, opt);
	}
	return (v->str_opt = ft_strdup(""), opt.process_invalide = 1, opt);
}

static char		*process_opt(t_var *v, va_list ap, fcts_flag *f, fcts_conv *c)
{
	char		*str;

	*v->opt = process_flag(v, f);
	if (v->opt->process_invalide == 1)
	{
		if (ft_isalpha(*v->s1))
			return (ft_format(ft_strdup(&v->opt->type_conv), *v->opt, 'n'));
		return (ft_strdup(&v->opt->type_conv));
	}
	else if (*v->s1 == 'x')
		return (ft_format(handle_hexa(ap, *v->opt, 0), *v->opt, *v->s1));
	else if (*v->s1 == 'X')
		return (ft_format(handle_hexa(ap, *v->opt, 1), *v->opt, *v->s1));
	else if (ft_strchr(OPT_CONV_U, *v->s1))
		f['l'](v->s1, v->opt);
	return (ft_format(c[ft_tolower(*v->s1)](ap, v->opt), *v->opt, *v->s1));
}

static	char	*replace_str(t_init *init, t_var *v)
{
	int			len;
	t_replace	rep;
	char		*str;
	static int test = 0;

	test++;
	len = v->opt->lenght > 0 ? v->opt->lenght - 1 : 1;
	if ((ft_tolower(*v->s1) == 'c') && v->ropt[len] == '\0')
		rep.ns2 = (v->opt->lenght > 0) ? v->opt->lenght : 1;
	else
		rep.ns2 = ft_strlen(v->ropt);
	rep = (t_replace) {.s1 = init->sf, .mod = v->str_opt, .s2 = v->ropt,
		.jump = v->cmp, .ns1 = init->strlen, .ns2 = rep.ns2};
	str = ft_printf_replace(rep, v);
	free(init->sf);
	return (str);
}

static	char	*parse_opt(t_init *init, fcts_flag *f, fcts_conv *c)
{
	t_var		v;

	ft_bzero(&v, sizeof(v));
	v = (t_var) {.init = init, .opt = ft_memset(&init->opt, 0, sizeof(t_opt))};
	v.cmp = 0;
	v.s1 = init->sf;
	while (v.s1 && (v.s1 = ft_strchr(v.s1, '%')) && init->opt.error >= 0)
	{
		v.ropt = process_opt(&v, init->ap, f, c);
		init->sf = replace_str(init, &v);
		v.cmp += *v.ropt == '%' ? 1 : 0;
		ft_strndel(2, &v.str_opt, &v.ropt);
	}
	return (init->sf);
}

int			ft_printf(char *str, ...)
{
	static fcts_flag	fcts_f[126] = { NULL };
	static fcts_conv	fcts_c[126] = { NULL };
	static int			setup = 0;
	t_init				init;

	if (setup == 0)
	{
		setup_fcts(fcts_f, fcts_c);
		setup = 1;
	}
	init.return_error = 0;
	init.strlen = ft_strlen(str);
	init.sf = ft_strdup(str);
	va_start(init.ap, str);
	init.sf = parse_opt(&init, fcts_f, fcts_c);
	va_end(init.ap);
	if (init.return_error < 0)
		return (init.return_error);
	else if (init.sf)
		return (ft_putnstr(init.sf, init.strlen), init.strlen);
	else
		return (-1);
}
