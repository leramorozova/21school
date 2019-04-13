/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:03:42 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/01 19:35:18 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(const char *s1, const char *s2);

int	main(void)
{
	printf("%d\n", ft_strcmp(ft_strnstr(buf2, "ozaraboze", 15), "ozaraboze123"));
	printf("%d\n", strcmp(ft_strnstr(buf2, "ozaraboze", 15), "ozaraboze123"));
	return (0);
}
