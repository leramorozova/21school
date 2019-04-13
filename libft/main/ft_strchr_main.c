/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:26:32 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 16:03:19 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strchr(const char *s, int c);

int		main (void)
{
	printf("%s\n", ft_strchr("success", 'c'));
	printf("%s\n", strchr("success", 'c'));
	return (0);
}
