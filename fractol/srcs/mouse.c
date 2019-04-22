/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 09:25:48 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/22 17:38:59 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		zoom(int key, int x, int y, t_fctl *param)
{
	x += x;
	y += y;
	if (key == 5)
	{
		param->zoom *= 1.2;
		redraw_img(param);
	}
	else if (key == 4)
	{
		param->zoom /= 1.2;
		redraw_img(param);
	}
}

int				mouse_press(int key, int x, int y, t_fctl *param)
{
	if (key == 4 || key == 5)
		zoom(key, x, y, param);
	if (key == 1)
		param->fix_mouse = param->fix_mouse == 1 ? 0 : 1;
	return (0);
}

int				mouse_move(int x, int y, t_fctl *param)
{
	double	x_copy;
	double	y_copy;

	x_copy = (double)x;
	y_copy = (double)y;
	if (param->fix_mouse == 1 || (ft_strcmp(param->title, "Julia")))
		return (0);
	else
	{
		param->real_unit_change = x_copy / 1000;
		param->im_unit_change = y_copy / 1000;
		redraw_img(param);
		return (0);
	}
}
