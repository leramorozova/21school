# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:57:11 by sdurgan           #+#    #+#              #
#    Updated: 2019/01/08 20:17:28 by sdurgan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

SRCS = validation.c main.c list_processing.c fillit.c

FLAGS = -Wall -Werror -Wextra
INCS = fillit.h
GCC = gcc

all: $(NAME)

$(NAME): $(SRCS)
	cd libft && $(MAKE)
	$(GCC) $(FLAGS) $(SRCS) -L./libft/ -lft -o $(NAME)

clean:
	cd libft && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft && make fclean

re: fclean all
