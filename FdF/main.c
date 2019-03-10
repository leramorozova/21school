/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:50:57 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/10 17:12:26 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// x_event
// 2 - нажатие клавиши клавы
// 3 - разжатие клавиши клавы
// 4 - нажатие мышки
// 5 - разжатие мышки
// 6 - движение мышки
// 12 - expose event??
// 17 - нажатие крестика на всплывающем окне

int close_window(t_mlx *param)
{
	del_map(&(param->map));
	exit(0);
	return (0);
}

int		key_press(int key, void *param)
{
	if (key == 53)
		close_window(param);
	if (key == 18)
		ft_putchar('X');
	if (key == 19)
		ft_putchar('y');
	return (0);
}

//void			redraw_image()

static t_mlx	init_mlx(int x, int y, char *filename)
{
	t_mlx	mlx;
	t_map	*map;
	int		bpp;
	int		size_line;
	int		endian;

	map = NULL;
	mlx.map = read_map(filename, map, &mlx);
	mlx.zoom = 600 / mlx.width;
	mlx.window_x = mlx.width * mlx.zoom + 200 < 2500 ? mlx.width *
		mlx.zoom + 300 : 2500;
	mlx.window_y = mlx.height * mlx.zoom + 200 < 1400 ? mlx.height * mlx.zoom
		+ 300 : 1400;
	mlx.offset_x = mlx.window_x / 2 - (mlx.width * mlx.zoom) / 2;
	mlx.offset_y = mlx.window_y / 2 - (mlx.height * mlx.zoom) / 2;
	mlx.init_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.init_ptr, mlx.window_x, mlx.window_y, filename);
	mlx.img_ptr = mlx_new_image(mlx.init_ptr, mlx.window_x, mlx.window_y);
	mlx.img_data = mlx_get_data_addr(mlx.img_ptr, &bpp, &size_line, &endian);
	mlx.int_data = (int *)mlx.img_data;
	return (mlx);
}

// idx = X position + Line size * Y position
int		main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		mlx = init_mlx(800, 400, argv[1]);
		put_map(&mlx, mlx.map);
		mlx_put_image_to_window(mlx.init_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
		mlx_hook(mlx.win_ptr, 2, 0, key_press, &mlx);
		mlx_mouse_hook(mlx.win_ptr, mouse_press, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
		mlx_loop(mlx.init_ptr);
	}
	return (0);
}
