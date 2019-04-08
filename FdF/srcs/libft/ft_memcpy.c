/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:37:08 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/02 13:06:41 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*copy_dst;
	char	*copy_src;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	copy_dst = (char *)dst;
	copy_src = (char *)src;
	while (i < n)
	{
		copy_dst[i] = copy_src[i];
		i++;
	}
	return (dst);
}
