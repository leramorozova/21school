# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 14:53:13 by sdurgan           #+#    #+#              #
#    Updated: 2019/04/22 17:58:31 by sdurgan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fractol

SRCS = srcs/draw.c srcs/fractol.c srcs/keyboard.c srcs/mouse.c srcs/main.c
INCS = /usr/local/include
LFTDIR = /srcs/libft
LFTFLAGS = -lft
LMATHFLAG = -lmath
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXDIR = /minilibx_macos
GCC = gcc -std=c99 -lpthread -Wall -Werror -Wextra 

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