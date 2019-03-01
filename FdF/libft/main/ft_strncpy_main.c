/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:17:39 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/21 15:34:40 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n);

int		main(void)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 50);
	printf("%s", ft_strncpy(dest, "Hello!", 4));
	return (0);
}
