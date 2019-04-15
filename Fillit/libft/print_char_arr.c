/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:16:39 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/08 15:33:23 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_putstr(arr[i++]);
		ft_putchar('\n');
	}
}