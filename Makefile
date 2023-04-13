# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlamber <arlamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 13:06:51 by arlamber          #+#    #+#              #
#    Updated: 2023/03/14 18:09:11 by arlamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c \
		parsing.c \
		get_next_line.c \
		get_next_line_utils.c \
		get_map.c \
		libft.c \
		parsing2.c \
		display.c \
		parsing3.c \
		hook.c \
		player_pos.c \
		ft_free.c \
		parsing4.c \
		libft2.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc
RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	so_long

PATH_MLX	=	./minilibx-linux

%.o: %.c
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -O3 -c $< -o $@

LINUX	=	-I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

$(NAME): $(OBJS) get_next_line.h so_long.h
		make -C $(PATH_MLX) all
		$(CC) $(CFLAGS) $(OBJS) minilibx-linux/libmlx_Linux.a $(LINUX) -o $(NAME)

all:	$(NAME)

clean:
		rm -rf $(OBJS)

fclean:		clean
		make -C $(PATH_MLX) clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re