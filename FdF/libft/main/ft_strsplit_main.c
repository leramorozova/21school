/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:26:00 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/03 13:31:17 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char    **ft_strsplit(char const *s, char c);

int		main(void)
{
	char	**test;
	int		i;

	i = 0;
	test = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing \
			elit. Sed non risus. Suspendisse lectus tortor, dignissim sit \
			amet, adipiscing nec, ultricies sed, dolor. Cras elementum \
		   	ultricies diam. Maecenas ligula massa, varius a, semper congue, \
			euismod non, mi.", 'i');

	print_char_arr(test);
	return (0);
}
