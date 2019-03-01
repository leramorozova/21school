/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:32:00 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 12:36:51 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int		main(void)
{
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", ft_strlen("HELLO!"));
	printf("%zu\n", ft_strlen("PINEAPPLEPAN"));
	printf("%zu\n", ft_strlen("	"));
	return (0);
}
