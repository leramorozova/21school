/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:07:34 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/10 18:11:19 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img		init_img(void *mlx, int width, int height)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.img = mlx_new_image(mlx, img.width, img.height);
	if (!img.img)
	{
		img.data = NULL;
		return (img);
	}
	img.data = (unsigned int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.size_line, &img.end);
	return (img);
}

int			draw_img(void *mlx, void *win, t_img img)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	while (++x != 361)
	{
		while (++y != 141)
			y == 140 || x == 360 ? mlx_pixel_put(mlx, win, x, y, 0xFFFFFF) :
				mlx_pixel_put(mlx, win, x, y, 0x000000);
		y = -1;
	}
	mlx_string_put(mlx, win, 10, 5, 0xFFFFFF, "press `esc` or [x] to leave\n");
	mlx_string_put(mlx, win, 10, 30, 0xFFFFFF, "mouse scroll: zoom\n");
	mlx_string_put(mlx, win, 10, 55, 0xFFFFFF,
			"left shift: change projection\n");
	mlx_string_put(mlx, win, 10, 80, 0xFFFFFF,
			"up, down, right, left: move figure");
	mlx_string_put(mlx, win, 10, 105, 0xFFFFFF, "num pad up, down: change z");
	return (0);
}

t_pixel		init_pixel(double x, double y, double z, unsigned int color)
{
	t_pixel	pix;

	pix.x = x;
	pix.y = y;
	pix.z = z;
	pix.color = color;
	return (pix);
}

void		copy_point(t_pixel *source, t_pixel *copy)
{
	copy->x = source->x;
	copy->y = source->y;
	copy->z = source->z;
	copy->color = source->color;
	copy->right = NULL;
}

t_pixel		*copy_pixel(t_pixel *source)
{
	t_pixel		*begin_source;
	t_pixel		*begin_copy;
	t_pixel		*copy;

	begin_source = source;
	copy = (t_pixel *)malloc(sizeof(t_pixel));
	begin_copy = copy;
	copy_point(source, copy);
	while (source)
	{
		if (source->right && !(copy->down = NULL))
		{
			copy->right = (t_pixel *)malloc(sizeof(t_pixel));
			copy_point(source->right, copy->right);
		}
		if (source->down)
		{
			copy->down = (t_pixel *)malloc(sizeof(t_pixel));
			copy_point(source->down, copy->down);
		}
		copy = copy->right;
		source = source->right;
	}
	source = begin_source;
	return (begin_copy);
}
