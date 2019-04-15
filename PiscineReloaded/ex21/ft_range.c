/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:07:55 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/20 19:28:27 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int len;
	int i;
	int *range;

	if (min >= max)
		return (0);
	len = 0;
	i = min;
	while (i < max)
	{
		len++;
		i++;
	}
	range = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (min != max)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}
