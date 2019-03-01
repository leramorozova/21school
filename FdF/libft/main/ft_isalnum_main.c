/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:17:21 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/23 19:02:50 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int ft_isalnum(int  c);

int	main(void)
{
	printf("%d\n", ft_isalnum('c'));
	printf("%d\n", isalnum('c'));
	printf("%d\n", ft_isalnum('C'));
	printf("%d\n", isalnum('C'));
	printf("%d\n", ft_isalnum(' '));
	printf("%d\n", isalnum(' '));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", isalnum('1'));
	printf("%d\n", ft_isalnum(1));
	printf("%d\n", isalnum(1));
	return (0);
}
