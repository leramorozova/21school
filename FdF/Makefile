# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:57:11 by sdurgan           #+#    #+#              #
#    Updated: 2019/03/12 14:05:12 by sdurgan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf

SRCS = main.c map_processing.c drawing.c mouse.c keyboard.c gradient_maker.c

INCS = /usr/local/include
LIB = minilibx_macos/libmlx.a -lmlx -framework OpenGL -framework AppKit
GCC = gcc

all: $(NAME)

$(NAME): $(SRCS)
	cd libft && $(MAKE)
	$(GCC) $(SRCS) $(LIB)  -L./libft/ -lft -o $(NAME)

clean:
	cd libft && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft && make fclean

re: fclean all
