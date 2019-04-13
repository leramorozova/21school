/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:39:31 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 12:42:52 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strdup(const char *s);

int		main(void)
{
	printf("%s\n", ft_strdup("Hello!"));
	printf("%s\n", ft_strdup(""));
	printf("%s\n", ft_strdup("Hello! Hi!"));
	return (0);
}
