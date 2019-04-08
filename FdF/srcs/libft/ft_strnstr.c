/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:19:44 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 19:56:17 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	target_len;
	size_t	i;
	size_t	j;
	int		flag;

	if (!needle && !hay)
		return (0);
	else if (needle[0] == '\0')
		return ((char *)hay);
	target_len = ft_strlen(needle);
	i = 0;
	flag = 1;
	while (flag != 0 && hay[i] != '\0' && target_len + i <= n)
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *)&(hay[i]));
		if (hay[i + j] == '\0')
			flag = 0;
		i++;
	}
	return (0);
}
