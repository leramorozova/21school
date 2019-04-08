/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:12:07 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/08 18:51:40 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		move_figure(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->map.move_y -= 10;
	else if (key == 125)
		fdf->map.move_y += 10;
	else if (key == 124)
		fdf->map.move_x += 10;
	else if (key == 123)
		fdf->map.move_x -= 10;
	redraw_image(fdf);
}

static void		put_flatten(t_fdf *fdf)
{
	static t_pixel		*temp;

	if (fdf->prj == 3)
	{
		temp = fdf->map.pixel;
		fdf->map.pixel = fdf->map.flatten;
		redraw_image(fdf);
		fdf->prj = 2;
	}
	else if (fdf->prj == 2)
	{
		fdf->map.pixel = temp;
		redraw_image(fdf);
		fdf->prj = 3;
	}
}

static void		plus_z(int key, t_fdf *fdf)
{
	t_pixel			*begin;
	t_pixel			*save;

	save = copy_pixel(fdf->map.flatten);
	begin = fdf->map.flatten;
	fdf->map.change_z += key == 116 ? 1 : -1;
	while (fdf->map.flatten)
	{
		fdf->map.flatten->z *= fdf->map.flatten->z == 0 ? 0 : fdf->map.change_z;
		if (fdf->map.flatten->down)
			fdf->map.flatten->down->z *= fdf->map.flatten->down->z == 0 ?
				0 : fdf->map.change_z;
		fdf->map.flatten = fdf->map.flatten->right;
	}
	fdf->map.flatten = begin;
	fdf->map.pixel = fdf->map.flatten;
	prj_iso(&(fdf->map));
	redraw_image(fdf);
	fdf->map.flatten = save;
}

int				keyboard(int key, t_fdf *param)
{
	if (key == 53)
		exit(0);
	if (key == 126 || key == 125 || key == 124 || key == 123)
		move_figure(key, param);
	if (key == 257)
		put_flatten(param);
	if (key == 116 || key == 121)
		plus_z(key, param);
	return (0);
}
