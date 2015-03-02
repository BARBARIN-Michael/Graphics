#include <ft_printf.h>

char	*add_precision(char *str, t_opt *opt,  int mod)
{
	char	c;
	char	*s1;
	int		start;

	s1 = str;
	if (!opt->opt_dot)
		return (str);
	start = !ft_isdigit(*str) ? 1 : 0;
	c = ft_strchr("diupxXoO", mod) ? '0' : ' ';
	if (mod != 's' && opt->precision > ft_strlen(str))
		s1 = ft_strset(str, start, opt->precision - ft_strlen(str) + start, c);
	else if (mod == 's' && opt->precision < ft_strlen(str))
		return (ft_strsub(str, 0, opt->precision));
	else if (ft_strchr("di", mod) && ft_atoi(str) == 0 &&
			(opt->opt_dot && opt->precision < ft_strlen(str)))
		return (ft_strdup(""));
	else if ((ft_strchr("oO", mod) && ft_atoi(str) == 0) || !s1)
		return (ft_strdup(""));
	return (s1);
}

char	*add_lenght(char *str, t_opt *opt,  int mod)
{
	char	*s1;
	char	c;
	int		pos;
	int		offset;

	s1 = str;
	if (opt->lenght == 0)
		return (str);
	c = opt->opt_0 ? '0' : ' ';
	c = opt->opt_dot && opt->precision == ft_strlen(str)
											&& ft_strchr("di", mod) ? ' ' : c;
	pos = 0;
	offset = ((*str == '-' || *str == '+' || *str == ' ') &&
			!ft_strchr("SC", mod)) ? 1 : 0;
	pos = opt->opt_neg ? ft_strlen(str) : pos;
	if (opt->lenght > ft_strlen(str))
		s1 = ft_strset(str, pos + offset, opt->lenght - ft_strlen(str), c);
	return (s1);
}

char	*add_0(char *str, t_opt *opt, int mod)
{
	char *s1;
	if (opt->opt_0 && !opt->opt_neg &&
			(ft_strchr("diouxX", mod) && opt->precision == 0)
			&& ft_atoi(str) != 0)
	{
		if (opt->opt_dot && opt->precision == ft_strlen(str) && ft_strchr("di", mod))
			return (str);
		return (ft_strjoin_free("0", str, 'r'));
	}
	return (str);
}

char	*add_sharp(char *str, t_opt *opt, int mod)
{
	char hexa[3];

	ft_insert(hexa, 2, "0");
	if ((ft_strchr("oOxX", mod) && !opt->opt_sharp)
			|| !ft_strchr("xXoOp", mod))
		return (str);
	if (mod == 'p' || (mod == 'x' && opt->opt_sharp))
		ft_insert(hexa, 3, "0x");
	else if (mod == 'X' && opt->opt_sharp)
		ft_insert(hexa, 3, "0X");
	if (ft_strchr("oOxX", mod) && opt->lenght == 0)
		if (ft_atoi(str) == 0)
			return (str);
	if (mod == 'p' && ft_atoi(str) == 0 && (opt->opt_dot && opt->precision == 0))
		return (ft_strdup("0x"));
	return (ft_strjoin_free(hexa, str, 'r'));
}

char	*add_pos(char *str, t_opt *opt, int mod)
{
	if (opt->opt_pos && ft_strchr("diD", mod) && ft_isdigit(*str))
	{
		opt->opt_space = 0;
		return (ft_strjoin_free("+", str, 'r'));
	}
	return (str);
}

char	*add_space(char *str, t_opt *opt, int mod)
{
	if (opt->opt_space && ft_strchr("di", mod) && ft_isdigit(*str)
			&& opt->opt_pos == 0)
	{
		return (ft_strjoin_free(" ", str, 'r'));
	}
	return (str);
}
