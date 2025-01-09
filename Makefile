# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 21:15:06 by ilbonnev          #+#    #+#              #
#    Updated: 2025/01/09 21:56:04 by ilbonnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -arch arm64
#CFLAGS = -Wall -Werror -Wextra

SRCS = src/main.c $(wildcard src/game/*.c) $(wildcard src/map/*.c) $(wildcard src/rendering/*.c)
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBMLX = minilibx/libmlx.a

NAME = so_long
MLX_FLAGS = -L/opt/homebrew/Cellar/libx11/1.8.10/lib -lX11 -lXext -framework OpenGL -framework AppKit
#MLX_FLAGS = -L/usr/lib -L/usr/include/X11 -lX11 -lXext -lGL

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	make -C minilibx/
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft/ clean
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
