/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:29:55 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/02 16:22:49 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*fresh;
	size_t	i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	fresh = (char *)malloc(sizeof(char) * (size + 1));
	if (!fresh)
		return (NULL);
	while (i < size)
	{
		fresh[i] = f((unsigned int)i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
