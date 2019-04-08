/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:49:28 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/08 16:48:30 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			put_pix_img(void *mlx, void *mx, t_pixel p)
{
	t_mlx			*m;
	t_img			*img;
	unsigned int	color;

	m = (t_mlx *)mx;
	img = &(m->img);
	if ((p.y < img->height) && (p.y > 0) && (p.x < img->width) && (p.x > 0))
		img->data[(int)p.y * img->width + (int)p.x] = p.color;
	return (1);
}

void		redraw_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx.mlx_init, fdf->mlx.img.img);
	fdf->mlx.img = init_img(fdf->mlx.mlx_init, fdf->mlx.win, fdf->mlx.width,
			fdf->mlx.height);
	put_map(&(fdf->map), fdf);
	draw_img(fdf->mlx.mlx_init, fdf->mlx.win, fdf->mlx.img);
}

static int	close_window(t_fdf *param)
{
	exit(0);
}

int			main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		fill_map(&fdf, argv[1]);
		fdf.mlx = init_mlx(mlx_init(), WIN_W, WIN_H);
		init_win(&fdf.mlx, fdf.map.name, fdf.mlx.width, fdf.mlx.height);
		fdf.mlx.img = init_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.width,
				fdf.mlx.height);
		put_map(&fdf.map, &fdf);
		draw_img(fdf.mlx.mlx_init, fdf.mlx.win, fdf.mlx.img);
		mlx_hook(fdf.mlx.win, 4, 0, mouse, &fdf);
		mlx_hook(fdf.mlx.win, 2, 0, keyboard, &fdf);
		mlx_hook(fdf.mlx.win, 17, 0, close_window, &fdf);
		mlx_loop(fdf.mlx.mlx_init);
	}
	else
		return (write(1, "\tUsage: ./fdf filename\n", 23));
}
