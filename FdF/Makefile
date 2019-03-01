# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:57:11 by sdurgan           #+#    #+#              #
#    Updated: 2019/03/01 19:51:31 by sdurgan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf

SRCS = try.c

FLAGS = -Wall -Werror -Wextra
INCS = /usr/local/include
LIB = minilibx_macos/libmlx.a
LIB_FLAGS = -lmlx -framework OpenGL -framework AppKit
GCC = gcc

all: $(NAME)

# Не забыть добавить флаги!
$(NAME): $(SRCS)
	cd libft && $(MAKE)
	$(GCC) $(SRCS) $(LIB) $(LIB_FLAGS) -L./libft/ -lft -o $(NAME)

clean:
	cd libft && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft && make fclean

re: fclean all
