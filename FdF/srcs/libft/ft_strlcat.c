/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:54:55 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 16:26:33 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	k;
	size_t	min;

	i = 0;
	j = ft_strlen(dest);
	k = ft_strlen(src);
	while (src[i] && i + j + 1 < size)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	min = size < j ? size : j;
	return (min + k);
}
