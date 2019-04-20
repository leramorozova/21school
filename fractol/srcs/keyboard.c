/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:17:42 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/20 11:53:15 by sdurgan          ###   ########.fr       */
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

int				keyboard(int key, t_fctl *param)
{
	if (key == 126 || key == 125 || key == 124 || key == 123)
		move_figure(key, param);
	if (key == 36)
	{
		make_julia_default(param);
		redraw_img(param);
	}
	return (0);
}
