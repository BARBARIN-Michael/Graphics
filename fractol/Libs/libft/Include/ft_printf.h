/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:46:00 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/03 11:18:24 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
#include <stdint.h>
# include <stdarg.h>
# define OPT_CONV   "bsSpdDioOuUxXcC%"
# define OPT_CONV_N "bspdiouxcSC%"
# define OPT_CONV_U "DOU"
# define BASE_16X   "0123456789abcdef"
# define BASE_16X_U "0123456789ABCDEF"
# define BASE_10    "0123456789"
# define BASE_8     "01234567"
# define BASE_2     "01"
# define BASE_32    32

typedef struct	s_opt
{
	int					opt_base;
	unsigned int		opt_sharp	: 1;
	unsigned int		opt_pos		: 1;
	unsigned int		opt_neg		: 1;
	unsigned int		opt_0		: 1;
	unsigned int		opt_space	: 1;
	unsigned int		opt_dot		: 1;
	unsigned int		opt_wchar	: 1;
	enum
	{
		opt_none,
		opt_l,
		opt_ll,
		opt_h,
		opt_hh,
		opt_j,
		opt_z
	}					opt_type;
	int					precision;
	int					lenght;
}				t_opt;

typedef struct s_var
{
	char	*ropt;
	char	*s1;
	char	*st;
	char	*sf;
	char	*str_opt;
	int		cmp;
	int		i;
	int		end;
	t_opt	*opt;
}				t_var;

typedef struct	s_init
{
	va_list	ap;
	t_opt	opt;
	char	*sf;
	size_t	strlen;
}				t_init;

typedef struct	s_replace
{
	char	*s1;
	char	*s2;
	char	*mod;
	size_t	jump;
	size_t	ns1;
	size_t	ns2;
}				t_replace;

typedef char *(*fcts_flag)(char *, t_opt *);
typedef char *(*fcts_conv)(va_list, t_opt);
typedef	char *(*fcts_spe)(uintmax_t, char *);

int		ft_printf(char *str, ...);
char	*process_special(t_opt, va_list, char *, fcts_spe spe);
char	*process_format(char *, t_opt, int);
char	*ft_process_hexa(va_list, t_opt, int);
char	*ft_process_lenght(char *, t_opt *);
char	*handle_percent(va_list, t_opt);
char	*handle_decimal(va_list, t_opt);
char	*handle_uint(va_list, t_opt);
char	*handle_binaire(va_list, t_opt);
char	*handle_oct(va_list, t_opt);
char	*handle_ptr(va_list, t_opt);
char	*handle_str(va_list, t_opt);
char	*handle_wstr(va_list, t_opt);
char	*handle_char(va_list, t_opt);
char	*handle_wchar(va_list, t_opt);
char	*handle_l(char *, t_opt *);
char	*handle_h(char *, t_opt *);
char	*handle_j(char *, t_opt *);
char	*handle_z(char *, t_opt *);
char	*handle_sharp(char *, t_opt *);
char	*handle_0(char *, t_opt *);
char	*handle_space(char *, t_opt *);
char	*handle_pos(char *, t_opt *);
char	*handle_neg(char *, t_opt *);
char	*handle_dot(char *, t_opt *);
char	*ft_printf_replace(t_replace rep);
#endif
