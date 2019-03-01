/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:17:21 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/23 18:44:34 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int ft_isalpha(int  c);

int	main(void)
{
	printf("%d\n", ft_isalpha('c'));
	printf("%d\n", isalpha('c'));
	printf("%d\n", ft_isalpha('C'));
	printf("%d\n", isalpha('C'));
	printf("%d\n", ft_isalpha(' '));
	printf("%d\n", isalpha(' '));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", isalpha('1'));
	printf("%d\n", ft_isalpha(1));
	printf("%d\n", isalpha(1));
	return (0);
}
