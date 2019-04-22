/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:17:42 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/22 15:36:14 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		move_figure(int key, t_fctl *fctl)
{
	if (key == 126)
		fctl->move_y += 0.1 / fctl->zoom;
	else if (key == 125)
		fctl->move_y -= 0.1 / fctl->zoom;
	else if (key == 124)
		fctl->move_x -= 0.1 / fctl->zoom;
	else if (key == 123)
		fctl->move_x += 0.1 / fctl->zoom;
	redraw_img(fctl);
}

int				change_iterations(int key, t_fctl *fctl)
{
	if (fctl->max_i >= 100)
	{
		fctl->max_i += key == 116 ? 10 : -10;
		redraw_img(fctl);
	}
	else if (fctl->max_i <= 100 && key == 116)
		fctl->max_i += 10;
	return (0);
}

int				color_schema(t_fctl *f, int i)
{
	if (f->change_color == 0)
		return (((50 * i % 256) << 16) | ((80 * i % 256) << 8) |
				(120 * i % 256));
	else if (f->change_color == 1)
		return (i * 256);
	else if (f->change_color == 2)
		return (i * 265);
	else
		return (0);
}

int				keyboard(int key, t_fctl *param)
{
	if (key == 126 || key == 125 || key == 124 || key == 123)
		move_figure(key, param);
	if (key == 36)
	{
		make_fractol_default(param);
		redraw_img(param);
	}
	if (key == 116 || key == 121)
		change_iterations(key, param);
	if (key == 18)
	{
		param->change_color = 0;
		redraw_img(param);
	}
	if (key == 19 || key == 18 || key == 20)
	{
		param->change_color = key - 18;
		redraw_img(param);
	}
	return (0);
}
