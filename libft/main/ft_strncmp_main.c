/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:03:42 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/02 17:58:29 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	printf("%d\n", ft_strncmp("abcdefgh", "", 0));
	printf("%d\n", strncmp("abcdefgh", "", 0));
//	printf("%d\n", ft_strncmp("HEll!", "Hello!", 3));
//	printf("%d\n", strncmp("HEll!", "Hello!", 3));
//	printf("%d\n", ft_strncmp("Hello!", "Hell!", 6));
//	printf("%d\n", strncmp("Hello!", "Hell!", 6));
//	printf("%d\n", ft_strncmp("", "", 4));
//	printf("%d\n", strncmp("", "", 4));
}
