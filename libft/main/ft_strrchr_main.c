/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:26:32 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/22 16:04:35 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strrchr(const char *s, int c);

int		main (void)
{
	printf("%s\n", ft_strrchr("success", 'c'));
	printf("%s\n", strrchr("success", 'c'));
	return (0);
}
