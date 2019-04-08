/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:55:02 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 20:49:36 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*fresh;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	end = ft_strlen(s) == 0 ? 0 : ft_strlen(s) - 1;
	start = 0;
	i = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && end != 0)
		end--;
	if (start > end)
		return (ft_strdup("\0"));
	fresh = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!fresh)
		return (NULL);
	while (end >= start)
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}
