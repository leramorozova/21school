/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:10:35 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/17 16:04:24 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			put_pix_img(t_fctl *fractol, double x, double y, int color)
{
	if (y < WIN_H && y > -1 && x < WIN_W && x > -1)
		fractol->int_img[(int)y * WIN_W + (int)x] = color;
	return (0);
}

int			draw_img(t_fctl *frac)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	mlx_put_image_to_window(frac->mlx_init, frac->win, frac->img, 0, 0);
	/*while (++x != 361)
	{
		while (++y != 141)
			y == 140 || x == 360 ? mlx_pixel_put(frac->mlx_init, frac->win,
				x, y, 0xFFFFFF) : mlx_pixel_put(frac->mlx_init, frac->win,
					x, y, 0x000000);
		y = -1;
	}
	mlx_string_put(frac->mlx_init, frac->win, 10, 5, 0xFFFFFF,
		"There will bw some signs later\n");*/
	return (0);
}

int			get_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
