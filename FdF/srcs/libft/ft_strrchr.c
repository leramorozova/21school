/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:19:02 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 16:03:07 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		save;

	save = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if ((int)s[i] == c)
			save = i;
		i++;
	}
	if (c == '\0')
		return ((char *)&(s[i]));
	else if (save == -1)
		return (NULL);
	else
		return ((char *)&(s[save]));
}
