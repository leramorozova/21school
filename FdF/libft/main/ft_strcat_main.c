/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:07:59 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 15:04:27 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, const char *src);

int		main(void)
{
	char	ex1[10];
	char	ex2[3];
	char	*str = "test";
	char	buf[10] = {0};
	int		i;

	i = 0;
	while (i != 3)
		ex1[i++] = 'o';
	i = 0;
	while (i != 2)
		ex2[i++] = 'a';
	ex2[i] = '\0';
	//ft_strcat(ex1, ex2);
	//strcat(ex1, ex2);
	//printf("%s", ex1);
	//printf("%s", ft_strcat(ex1, ex2));
	printf("%s", ft_strcat(buf, str));
	return (0);
}
