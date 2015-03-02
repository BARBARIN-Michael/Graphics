#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:48:04 by mbarbari          #+#    #+#              #
#    Updated: 2015/02/16 18:19:09 by mbarbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = a.out
CP = cp

LIBFT_PATH ?= ../libft/

OBJDIR = ./Objets

CFLAGS += -g -O0 -I Include/ -I ../libft/Include/ -L ../libft/ -lft #-Wall -Wextra -Werror -I Include/

SRCS =	ft_printf.c \
		ft_setup.c \
		handle_flag_f.c \
		handle_flag_s.c \
		handle_format.c \
		handle_modifier.c \
		ft_integer.c \
		ft_pointer.c \
		ft_string.c \
		ft_hexa.c \
		ft_printf_replace.c \
		ft_make_format.c

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJS)
	$(CP) $(LIBFT_PATH)/libft.a $(NAME)
	$(AR) -rcs $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

fcleanall: fclean
	$(RM) $(EXE)

re: fclean all
