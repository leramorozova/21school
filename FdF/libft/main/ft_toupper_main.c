/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:24:20 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/25 18:43:13 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>


int	ft_toupper(int c);

int	main(void)
{
	printf("%c", ft_toupper(1));
	printf("%c", toupper(1));
	printf("%c", ft_toupper('A'));
	printf("%c", toupper('A'));
	printf("%c", ft_toupper('a'));
	printf("%c", toupper('a'));
	return (0);
}
