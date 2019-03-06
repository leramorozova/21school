/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:50:57 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/06 17:44:06 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// x_event
// 2 - нажатие клавиши клавы
// 3 - разжатие клавиши клавы
// 4 - нажатие мышки
// 5 - разжатие мышки
// 6 - движение мышки
// 12 - expose event??
// 17 - нажатие крестика на всплывающем окне

int close_window(void *param)
{
	del_map(param);
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
	if (key == 125 || key == 126)
		ft_putstr("UP-DOWN");
	return (0);
}

t_mlx	*init_mlx(int x, int y, char *filename)
{
	t_mlx	*mlx;
	int		bpp;
	int		size_line;
	int		endian;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->init_ptr = mlx_init();
	mlx->line_size = x;
	mlx->win_ptr = mlx_new_window(mlx->init_ptr, x, y, filename);
	mlx->img_ptr = mlx_new_image(mlx->init_ptr, x, y);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &bpp, &size_line, &endian);
	mlx->int_data = (int *)mlx->img_data;
	return (mlx);
}

// idx = X position + Line size * Y position
int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;

	if (argc == 2)
	{
		map = NULL;
		map = read_map(argv[1], map);
		mlx = init_mlx(800, 600, argv[1]);
		//put_line(&mlx, 10, 0, 10, 600);
		mlx_put_image_to_window(mlx->init_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		mlx_hook(mlx->win_ptr, 2, 0, key_press, map);
		mlx_hook(mlx->win_ptr, 17, 0, close_window, map);
		mlx_loop(mlx->init_ptr);
	}
	return (0);
}
