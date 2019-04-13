/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:31:30 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/29 13:34:36 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strstr(const char *haystack, const char *needle);

int		main(void)
{
	printf("%s\n", ft_strstr("MZIRIBMZIRIBMZP", "MZIRIBMZP"));
	printf("%s\n", strstr("MZIRIBMZIRIBMZP", "MZIRIBMZP"));
	printf("%s\n", ft_strstr("see F your F return FF now FF", "FF"));
	printf("%s\n", strstr("see F your F return FF now FF", "FF"));
	printf("%s\n", ft_strstr("lala", ""));
	printf("%s\n", strstr("lala", ""));
}
