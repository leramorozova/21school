/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 22:25:45 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/02 12:51:19 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_minus(int flags[11], int len,
						unsigned long long c, char *res)
{
	int		ret;
	int		i;
	int		tmp;

	ret = 0;
	if (flags[3])
		ret += write(1, "0", 1);
	i = -1;
	while (++i < flags[8] - flags[3] - len
			* (flags[8] - flags[3] >= len || c || !flags[10]))
		ret += write(1, "0", 1);
	if (c || flags[8] - flags[3] >= len || !flags[10])
		ret += write(1, res, len);
	i = -1;
	tmp = ret;
	while (++i < flags[7] - tmp)
		ret += write(1, " ", 1);
	return (ret);
}

static int		is_dot(int flags[11], int len,
						unsigned long long c, char *res)
{
	int		ret;
	int		tmp;
	int		i;

	ret = 0;
	tmp = len * (c || flags[8] - flags[3] >= len || !flags[10]);
	i = -1;
	while (++i < flags[7] - flags[3] - tmp
	- (flags[8] - tmp - flags[3]) * (flags[8] >= tmp + flags[3]))
		ret += write(1, " ", 1);
	if (flags[3])
		ret += write(1, "0", 1);
	i = -1;
	while (++i < flags[8] - flags[3] - tmp)
		ret += write(1, "0", 1);
	if (c || flags[8] - flags[3] >= len || !flags[10])
		ret += write(1, res, len);
	return (ret);
}

static int		no_dot(int flags[11], int len,
						unsigned long long c, char *res)
{
	int		ret;
	int		i;
	char	fill;

	ret = 0;
	if (flags[6])
		fill = '0';
	else
		fill = ' ';
	if (flags[6] && flags[3] && c != 0)
		ret += write(1, "0", 1);
	i = -1;
	while (++i < flags[7] - flags[3] * (c != 0) - len)
		ret += write(1, &fill, 1);
	if (!flags[6] && flags[3] && c != 0)
		ret += write(1, "0", 1);
	ret += write(1, res, len);
	return (ret);
}

int				print_octal(va_list ap, char ls[3], int flags[11])
{
	unsigned long long int	c;
	char					*res;
	char					*str;
	int						ret;

	if (ls[2] == 'O' || ls[0] == 'l' || ls[0] == 'j' ||
			ls[0] == 'z' || ls[0] == 't')
		c = va_arg(ap, unsigned long long int);
	else if (ls[0] == 'h' && ls[1] == 'h')
		c = (unsigned char)va_arg(ap, int);
	else if (ls[0] == 'h')
		c = (unsigned short int)va_arg(ap, int);
	else
		c = va_arg(ap, unsigned int);
	str = ft_itoa_unsigned_long(c);
	res = change_base(str, 10, 8, (ls[2] == 'o'));
	if (flags[2])
		ret = is_minus(flags, ft_strlen(res), c, res);
	else if (flags[10])
		ret = is_dot(flags, ft_strlen(res), c, res);
	else
		ret = no_dot(flags, ft_strlen(res), c, res);
	ft_strdel(&str);
	ft_strdel(&res);
	return (ret);
}
