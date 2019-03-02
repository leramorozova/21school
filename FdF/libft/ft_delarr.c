/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:03:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/02 14:24:09 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_delarr(char ***arr)
{
	int		t;

	t = 0;
	while ((*arr)[t])
	{
		ft_strdel(&((*arr)[t]));
		t++;
	}
	free(*arr);
	arr = NULL;
	return (0);
}
