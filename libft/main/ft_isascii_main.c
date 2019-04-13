/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:24:20 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/25 19:13:05 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>


int	ft_isascii(int c);

int	main(void)
{
	printf("%c", ft_isascii(1));
	printf("%c", isascii(1));
	printf("%c", ft_isascii('й'));
	printf("%c", isascii('й'));
	printf("%c", ft_isascii('\t'));
	printf("%c", isascii('\t'));
	return (0);
}
