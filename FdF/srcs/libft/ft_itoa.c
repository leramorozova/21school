/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:11:09 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 20:20:55 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(size_t len, int n)
{
	int	copy;

	copy = n;
	while (copy / 10 != 0)
	{
		len++;
		copy /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*ret;
	size_t		len;
	int			flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	flag = n < 0 ? -1 : 1;
	len = flag < 0 ? 2 : 1;
	len = ft_len(len, n);
	if (n == 0 && flag == 1)
		return (ft_strdup("0"));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len--] = '\0';
	while (n != 0)
	{
		ret[len--] = (n * flag % 10) + '0';
		n /= 10;
	}
	if (flag == -1)
		ret[0] = '-';
	return (ret);
}
