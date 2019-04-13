/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:07:59 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 15:10:09 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n);

int		main(void)
{
	char	ex1[10];
	char	ex2[3];
	int		i;
	char	*str = "testtest";
	char	buf[10] = {0};

	i = 0;
	while (i != 3)
		ex1[i++] = 'o';
	i = 0;
	while (ex2[i] != '\0')
		ex2[i++] = 'a';
	//ft_strcat(ex1, ex2);
	//strcat(ex1, ex2);
	printf("%s", ft_strncat(buf, str, 10));
	return (0);
}
