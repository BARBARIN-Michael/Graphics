#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:48:04 by mbarbari          #+#    #+#              #
#    Updated: 2015/04/20 22:21:33 by mbarbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = a.out
CP = cp


OBJDIR = ./Objets

LIBS = -L../libft/ -lft 
INC =  -I ../libft/Include/
CFLAGS += -g -O0 -Wall -Wextra -Werror -I ./Include/ $(INC)

SRCS =	Srcs/ft_printf.c \
		Srcs/ft_setup.c \
		Srcs/handle_flag_f.c \
		Srcs/handle_flag_s.c \
		Srcs/handle_format.c \
		Srcs/handle_modifier.c \
		Srcs/ft_integer.c \
		Srcs/ft_pointer.c \
		Srcs/ft_string.c \
		Srcs/ft_hexa.c \
		Srcs/ft_printf_replace.c \
		Srcs/ft_make_format.c \
		Srcs/ft_make_format2.c


LIBFT_PATH ?= ../libft/

OBJS = $(patsubst Srcs/%.c,Objets/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | Objets

Objets:
		@mkdir -p $@

Objets/%.o: Srcs/%.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT_PATH)/libft.a:
		$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS) 
	#$(LIBFT_PATH)/libft.a $(OBJS)
		#$(CP) $(LIBFT_PATH)/libft.a $(NAME)
			$(AR) -rcs $(NAME) $^

clean:
		$(RM) $(OBJS)

libfttest: $(NAME) Objets/main.o
		$(CC) -o $@ $^

fclean: clean
		$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re $(LIBFT_PATH)/libft.a



#OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))
#
#RM = rm -f
#
#
#all: $(NAME)
#
#$(OBJS): | Objets
#
#Objets:
#	@mkdir -p $@
#
#Objets/%.o: Srcs/%.c
#
#$(LIBFT_PATH)/libft.a:
#	$(MAKE) -C $(LIBFT_PATH)
#
#$(NAME):$(LIBFT_PATH)/libft.a $(OBJS)
#	$(CP) $(LIBFT_PATH)/libft.a $(NAME)
#	$(AR) -rcs $(NAME) $^
#
#clean:
#	$(RM) ./Objets/%.o
#
#fclean: clean
#	$(RM) $(NAME)
#
#fcleanall: fclean
#	$(RM) $(EXE)
#
#re: fclean all
