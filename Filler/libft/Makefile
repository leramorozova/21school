# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:12:54 by sdurgan           #+#    #+#              #
#    Updated: 2019/03/25 16:46:50 by sdurgan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_lstnew.c ft_putstr_fd.c ft_strncmp.c ft_memalloc.c ft_strcat.c \
ft_strncpy.c ft_memccpy.c ft_strchr.c ft_strnequ.c ft_atoi.c \
ft_memchr.c ft_strclr.c ft_strnew.c ft_bzero.c ft_memcmp.c ft_strcmp.c \
ft_strnstr.c ft_isalnum.c ft_memcpy.c ft_strcpy.c ft_strrchr.c \
ft_isalpha.c ft_memdel.c ft_strdel.c ft_strsplit.c ft_isascii.c \
ft_memmove.c ft_strdup.c ft_strstr.c ft_isdigit.c ft_memset.c \
ft_strequ.c ft_strsub.c ft_isprint.c ft_power.c ft_striter.c \
ft_strtrim.c ft_itoa.c ft_putchar.c ft_striteri.c ft_tolower.c \
ft_lstadd.c ft_putchar_fd.c ft_strjoin.c ft_toupper.c ft_lstadd_end.c \
ft_putendl.c ft_strlcat.c ft_lstdel.c ft_putendl_fd.c ft_strlen.c \
print_char_arr.c ft_lstdelone.c ft_putnbr.c ft_strmap.c print_list.c \
ft_lstiter.c ft_putnbr_fd.c ft_strmapi.c ft_lstmap.c ft_putstr.c \
ft_strncat.c ft_lstfree.c ft_lstfreeone.c ft_delarr.c ft_swap.c ft_sqrt.c \
get_next_line.c ft_abs.c ft_sign.c ft_wordscnt.c ft_itoa_base.c ft_atoi_base.c

OBJC = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJC)
	ar rcs $(NAME) $(OBJC)
	ranlib $(NAME)

$(OBJC): $(SRCS)
	gcc -Wall -Werror -Wextra -c $(SRCS)

clean:
	rm -f $(OBJC)

fclean:
	rm -f $(NAME)
	rm -f $(OBJC)

re: fclean all
