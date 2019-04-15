/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:34:35 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 16:19:20 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	while (len != 0)
	{
		fresh[i++] = s[start++];
		len--;
	}
	fresh[i] = '\0';
	return (fresh);
}
