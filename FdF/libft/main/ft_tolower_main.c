/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:24:20 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/25 18:57:01 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>


int	ft_tolower(int c);

int	main(void)
{
	printf("%c", ft_tolower(1));
	printf("%c", tolower(1));
	printf("%c", ft_tolower('A'));
	printf("%c", tolower('A'));
	printf("%c", ft_tolower('a'));
	printf("%c", tolower('a'));
	return (0);
}
