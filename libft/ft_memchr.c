/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:19:02 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 15:56:26 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy_s;

	copy_s = (unsigned char *)s;
	while (n != 0)
	{
		if (*copy_s == (unsigned char)c)
			return (copy_s);
		copy_s++;
		n--;
	}
	return (NULL);
}
