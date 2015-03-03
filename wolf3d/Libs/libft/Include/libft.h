/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:05:43 by mbarbari          #+#    #+#             */
/*   Updated: 2015/02/16 12:32:55 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"
# define TRUE			1
# define FALSE			0

typedef int			t_bool;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *);
char				*ft_itoa(intmax_t);
char				*ft_utoa(uintmax_t);
char				*ft_wtoa(wint_t);
char				*ft_ntoa(uintmax_t, char *);
int					ft_isalnum(int );
char				*ft_strcat(char *, const char *);
int					ft_isspace(int c);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
char				*ft_strjoin_free(char *src, char *join, int mod);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_bzero(void *s, size_t n);
char				*ft_realloc(char *str, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t len);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_strdel(char **as);
void				ft_strndel(int a, ...);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *src, int c);
int					ft_findchr(const char *src, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstrchr(const char *s1, const char *s2);
char				*ft_strsub(char const *s1, unsigned int start, size_t len);
char				*ft_wstrsub(char const *s1, unsigned int s, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcpy(char *dst, char *src);
size_t				ft_strlen(const char *str);
size_t				ft_wstrlen(const wchar_t *str);
int					ft_wlen(wchar_t c);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
char				**ft_strsplit(char const *s, char c);
int					ft_strcount(char *str, int c);
void				ft_putchar(char c);
void				ft_putwchar(wchar_t c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_c(char const *str, char *color);
void				ft_putendl2_c(char const *s1, char const *s2, char *color);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
int					ft_putnstr(char const *s, size_t n);
void				ft_putstr_c(char const *s, char *color);
void				ft_putstr_fd(char const *s, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_replace(char *, char *, char *);
char				*ft_nreplace(char *, char *, char *, size_t);
char				*ft_n1replace(char *s1, char *mod, char *s2, size_t n);
char				*ft_replace_free(char *, char *, char *, int);
long int			ft_strtol(char *line);
long				ft_pow(int valeur, int power);
int					ft_round(float);
int					ft_ceil(float);
char				*ft_strset(char *s1, int pos, int nbr, int car);
char				*ft_insert(char *tab, int elem, char *value);

#endif
