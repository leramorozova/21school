/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:50:30 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/29 14:39:57 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom(int key, int x, int y, t_fdf *param)
{
	if (key == 4)
	{
		if (param->map.scale > 700)
			return ;
		if (param->map.scale > 30)
			param->map.scale += 2;
		else if (param->map.scale > 300)
			param->map.scale += 6;
		param->map.scale += 2;
		redraw_image(param);
	}
	else if (key == 5)
	{
		if (param->map.scale - 2 < 1)
			return ;
		if (param->map.scale > 30)
			param->map.scale -= 2;
		else if (param->map.scale > 300)
			param->map.scale -= 6;
		param->map.scale -= 2;
		redraw_image(param);
	}
}

int		mouse(int key, int x, int y, t_fdf *param)
{
	if (key == 4 || key == 5)
		zoom(key, x, y, param);
	return (0);
}