/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:59:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/10 14:15:17 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int key, int x, int y, t_mlx *param)
{
	if (key == 5 && param->zoom > 10)
		param->zoom -= 5;
	if (key == 4 && param->zoom < 200)
		param->zoom += 5;
	ft_putnbr(param->zoom);
	ft_putchar('\n');
	return (0);
}
