# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:12:54 by sdurgan           #+#    #+#              #
#    Updated: 2018/11/20 19:29:35 by sdurgan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft.a

libft.a: 
	gcc -c srcs/*.c -I includes/*.h -Wall -Werror -Wextra
	ar rc libft.a *.o
	ranlib libft.a

clean:
	rm -f *.o

fclean:
	rm -f *.o
	rm -f *.a

re: fclean all
