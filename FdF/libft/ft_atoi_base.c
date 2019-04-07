/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:30:06 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/07 14:30:11 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		convert(char c, int base)
{
	int		result;

	if (c >= '0' && c <= '9')
		result = c - '0';
	else if (c >= 'a' && c <= 'z')
		result = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		result = c - 'A' + 10;
	else
		result = -1;
	if (result < base && result != -1)
		return (result);
	else
		return (-1);
}

static int		length_number(char *str, int base)
{
	int		length;

	length = 0;
	while (str[length])
	{
		if (convert(str[length], base) == -1)
			break ;
		length++;
	}
	return (length);
}

int				ft_atoi_base(char *nb, int base)
{
	int		res;
	int		length;

	if (base == 10)
		return (ft_atoi(nb));
	while (*nb == ' ' || *nb == '\t' || *nb == '\n'
			|| *nb == '\v' || *nb == '\r' || *nb == '\f')
		nb++;
	if (base == 16 && *nb == '0' && (*(nb + 1) == 'x'
				|| *(nb + 1) == 'X'))
		nb += 2;
	res = 0;
	length = length_number(nb, base) - 1;
	while (*nb && length >= 0 && convert(*nb, base) != -1)
	{
		res += convert(*nb, base) * ft_power(base, length);
		nb++;
		length--;
	}
	return (res);
}
