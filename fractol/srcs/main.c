/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:43:28 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/15 18:25:14 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_fctl *param)
{
	param = NULL;
	exit(0);
}

int			put_pix_img(t_fctl *fractol, double x, double y, int color)
{
	if (x * y < fractol->img_limit && x > -1 && y > -1)
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
	while (++x != 361)
	{
		while (++y != 141)
			y == 140 || x == 360 ? mlx_pixel_put(frac->mlx_init, frac->win,
				x, y, 0xFFFFFF) : mlx_pixel_put(frac->mlx_init, frac->win,
					x, y, 0x000000);
		y = -1;
	}
	mlx_string_put(frac->mlx_init, frac->win, 10, 5, 0xFFFFFF,
		"There will bw some signs later\n");
	return (0);
}

void		init_mlx(t_fctl *fractol, char *name)
{
	int				size_line;
	int				end;
	int				bits_per_pixel;

	fractol->mlx_init = mlx_init();
	fractol->title = name;
	fractol->win = mlx_new_window(fractol->mlx_init, WIN_W, WIN_H,
					fractol->title);
	fractol->img = mlx_new_image(fractol->mlx_init, WIN_W, WIN_H);
	fractol->int_img = (unsigned int *)mlx_get_data_addr(fractol->img,
					&bits_per_pixel, &size_line, &end);
	fractol->img_limit = WIN_W * WIN_H;
}

int			main(int argc, char **argv)
{
	t_fctl	fractol;

	if (argc == 2)
	{
		init_mlx(&fractol, argv[1]);
		//mlx_hook(fractol.mlx.win, 4, 0, mouse, &fdf);
		//mlx_hook(fdf.mlx.win, 2, 0, keyboard, &fdf);
		draw_img(&fractol);
		mlx_hook(fractol.win, 17, 0, close_window, &fractol);
		mlx_loop(fractol.mlx_init);
	}
	else
		return (write(1, "Usage: ./fractol fractol_name (e.g Julia)\n", 42));
}
