/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:18:58 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/02 13:09:33 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*copy_dst;
	const unsigned char	*copy_src;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	if (src > dst)
		while (i < n)
		{
			copy_dst[i] = copy_src[i];
			i++;
		}
	else if (src < dst)
	{
		while (n--)
			copy_dst[n] = copy_src[n];
	}
	return (dst);
}
