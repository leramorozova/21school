/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:59:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/10 18:10:07 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int key, int x, int y, t_mlx *param)
{
	ft_putnbr(param->zoom);
	if (key == 4 && param->zoom > 3)
	{
		param->zoom -= 2;
		redraw_image(param);
	}
	if (key == 5 && param->zoom < 200)
	{
		param->zoom += 2;
		redraw_image(param);
	}
	return (0);
}
