/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:43:04 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/07 17:09:53 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	if (size + 1 < size)
		return (NULL);
	i = 0;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	else
		ft_memset(s, '\0', size + 1);
	return (s);
}
