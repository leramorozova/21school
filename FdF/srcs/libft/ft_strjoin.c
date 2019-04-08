/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:47:41 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/30 10:44:06 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	fresh = (char *)malloc(sizeof(char) * len);
	if (!fresh)
		return (NULL);
	while (s1[i] != '\0')
		fresh[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		fresh[j++] = s2[i++];
	fresh[j] = '\0';
	return (fresh);
}
