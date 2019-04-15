/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:47:12 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/03 12:34:35 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	unsigned long long int		out;
	int							flag;
	size_t						i;
	unsigned long long int		temp;

	out = 0;
	flag = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		flag = nptr[i++] == '-' ? -1 : 1;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		temp = out;
		out *= 10;
		out += nptr[i++] - '0';
		if (temp > out)
			return (flag == 1) ? (-1) : (0);
	}
	return (flag * out);
}
