/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:51:01 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/30 18:34:37 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *nptr);

int	main(void)
{
	printf("%d\n", atoi("   -9223372036854775810"));
	printf("%d\n", ft_atoi("  -9223372036854775810"));
	printf("%d\n", atoi("   9223372036854775810"));
	printf("%d\n", ft_atoi("  9223372036854775810"));
	printf("%d\n", atoi("   "));
	printf("%d\n", ft_atoi("   "));
	printf("%d\n", atoi("   567   "));
	printf("%d\n", ft_atoi("   567   "));
	printf("%d\n", atoi("   t5   67   "));
	printf("%d\n", ft_atoi("   t5   67   "));
	printf("%d\n", atoi("-42"));
	printf("%d\n", ft_atoi("-42"));
	printf("%d\n", atoi("0"));
	printf("%d\n", ft_atoi("0"));
	return (0);
}
