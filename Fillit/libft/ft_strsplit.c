/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:22:58 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/03 15:00:59 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			word_count(char const *s, char c)
{
	int		word_count;
	size_t	i;

	i = 0;
	word_count = 0;
	if (ft_strlen(s) != 0)
		word_count = s[0] != c ? 1 : 0;
	while (s[i + 1] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			word_count++;
		i++;
	}
	return (word_count);
}

static size_t		word_len(char const *s, char c)
{
	size_t	start;
	int		len;

	len = 0;
	start = 0;
	while (s[start] == c)
		start++;
	while (s[start] != c && s[start] != '\0')
	{
		start++;
		len++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ret;

	if (!s)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count(s, c))
	{
		k = 0;
		if (!(ret[i] = (char *)malloc(sizeof(char) * word_len(&s[j], c))))
			return (ft_delarr(&ret, i) == 0) ? (NULL) : (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
			ret[i][k++] = s[j++];
		ret[i++][k] = '\0';
	}
	ret[i] = NULL;
	return (ret);
}
