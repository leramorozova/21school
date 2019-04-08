/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:37:08 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/02 13:07:06 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*copy_dst;
	const unsigned char	*copy_src;
	size_t				i;

	if (!dst && !src)
		return (0);
	i = 0;
	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	while (i < n)
	{
		copy_dst[i] = copy_src[i];
		if (copy_dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
