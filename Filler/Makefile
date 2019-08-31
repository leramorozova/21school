.PHONY: all clean fclean re

NAME = sdurgan.filler

SRCS = main.c

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