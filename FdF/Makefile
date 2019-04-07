.PHONY: all clean fclean re

NAME = fdf

SRCS = *.c
INCS = /usr/local/include
LFTDIR = /libft
LFTFLAGS = -lft
LMATHFLAG = -lmath
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXDIR = /minilibx_macos
GCC = gcc

all: $(NAME)

$(NAME): $(SRCS)
	cd libft && $(MAKE)
	$(GCC) -g $(SRCS) -L.$(MLXDIR) $(MLXFLAGS)  -L.$(LFTDIR) $(LFTFLAGS) -o $(NAME)

clean:
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all