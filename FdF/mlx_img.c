/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:07:34 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/07 13:23:06 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img		init_img(void *mlx, void *win, int width, int height)
{
    t_img   img;

    img.width = width;
    img.height = height;
    img.img = mlx_new_image(mlx, img.width, img.height);
    if(!img.img)
    {
        img.data = NULL;
        return (img);
    }
    img.data = (unsigned int *)mlx_get_data_addr(img.img, &img.bits_per_pixel,
                                                &img.size_line, &img.end);
	return(img);
}

int			draw_img(void *mlx, void *win, t_img img)
{
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_string_put(mlx, win, 10, 5, 0xFFFFFF, "press `esc` or [x] to leave\n");
	mlx_string_put(mlx, win, 10, 30, 0xFFFFFF, "mouse scroll: zoom\n");
	mlx_string_put(mlx, win, 10, 55, 0xFFFFFF,
			"left shift: change projection\n");
	mlx_string_put(mlx, win, 10, 80, 0xFFFFFF,
			"up, down, right, left: move figure");
	mlx_string_put(mlx, win, 10, 105, 0xFFFFFF, "num pad up, down: change z");
	return (0);
}

int 	put_pix_img(void *mlx, void *mx, t_pixel p)
{
    t_mlx			*m;
    t_img			*img;
    unsigned int	color;

    m = (t_mlx *)mx;
    img = &(m->img);
	if ((p.y < img->height) &&  (p.y > 0) && (p.x < img->width) &&  (p.x > 0))
        img->data[(int)p.y * img->width + (int)p.x] = p.color;
    return (1);
}