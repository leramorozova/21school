/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:17:39 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/21 15:23:55 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src);

int		main(void)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 50);
	printf("%s", ft_strcpy(dest, "Hello!"));
	return (0);
}
