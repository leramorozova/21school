/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 09:25:48 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/20 11:23:27 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		zoom(int key, int x, int y, t_fctl *param)
{
	x += x;
	y += y;
	if (key == 5)
	{
		//if (param->zoom > 700)
		param->zoom *= 1.2;
		redraw_img(param);
	}
	else if (key == 4)
	{
		param->zoom /= 1.2;
		redraw_img(param);
	}
}

int		mouse_press(int key, int x, int y, void *param)
{
	if (key == 4 || key == 5)
		zoom(key, x, y, param);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	return (0);
}
