# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 14:53:13 by sdurgan           #+#    #+#              #
#    Updated: 2019/04/08 18:34:52 by sdurgan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf

SRCS = srcs/colours.c srcs/draw.c srcs/isometry.c srcs/main.c \
	   srcs/mlx_graphics.c srcs/mlx_img.c srcs/mapping.c srcs/keyboard.c \
	   srcs/map_processing.c
INCS = /usr/local/include
LFTDIR = /srcs/libft
LFTFLAGS = -lft
LMATHFLAG = -lmath
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXDIR = /minilibx_macos
GCC = gcc

all: $(NAME)

$(NAME): $(SRCS)
	cd srcs/libft && $(MAKE)
	$(GCC) $(SRCS) -L.$(MLXDIR) $(MLXFLAGS) -L.$(LFTDIR) $(LFTFLAGS) -o $(NAME)

clean:
	cd srcs/libft && make clean

fclean: clean
	rm -f $(NAME)
	cd srcs/libft && make fclean

re: fclean all