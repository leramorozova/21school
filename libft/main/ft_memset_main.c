/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:23:27 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 18:33:55 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

int		main(void)
{
	char	*s;
	char	*t;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * 10);
	t = (char *)malloc(sizeof(char) * 10);
	s = memset(NULL, 1, 5);
	while (i < 10)
		printf("%d\n", s[i++]);
	printf("%s", "\n");
	t = memset(NULL, 1, 5);
	i = 0;
	while (i < 5)
		printf("%d\n", t[i++]);
	return (0);
}
