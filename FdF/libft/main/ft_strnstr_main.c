/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:31:30 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 18:11:35 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strnstr(const char *haystack, const char *needle, size_t n);

int		main(void)
{
	printf("%s\n", ft_strnstr("byekekbye", "bye", 3));
	printf("%s\n", strnstr("byebyekek", "bye", 3));
	printf("%s\n", ft_strnstr("byebyekek", "kek", 3));
	printf("%s\n", strnstr("byebyekek", "kek", 3));
	printf("%s\n", ft_strnstr("lalazu", "zuk", 6));
	printf("%s\n", strnstr("lalazu", "zuk", 6));
}
