/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:50:57 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/10 13:22:50 by sdurgan          ###   ########.fr       */
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

int close_window(void *param)
{
	del_map(param);
//	free(&((*param)->mlx));
//	param = NULL;
	exit(0);
	return (0);
}

int		key_press(int key, void *param)
{
	int		default_zoom;

	if (key == 53)
		close_window(param);
	if (key == 18)
		ft_putchar('X');
	if (key == 19)
		ft_putchar('y');
	return (0);
}

void	put_param(t_mlx *param)
{
	printf("%d", param->zoom);
}

int		mouse_press(int key, int x, int y, t_mlx *param)
{
	//put_param(param);
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
	if (key == 5)
		printf("UP");
	return(0);
}

t_mlx	init_mlx(int x, int y, char *filename)
{
	t_mlx	mlx;
	t_map	*map;
	int		bpp;
	int		size_line;
	int		endian;

	map = NULL;
	mlx.map = read_map(filename, map);
	mlx.init_ptr = mlx_init();
	mlx.line_size = x;
	mlx.win_ptr = mlx_new_window(mlx.init_ptr, x, y, filename);
	mlx.img_ptr = mlx_new_image(mlx.init_ptr, x, y);
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
		mlx = init_mlx(800, 600, argv[1]);
		mlx.zoom = 10;
		put_map(&mlx, mlx.map, 20);
		mlx_put_image_to_window(mlx.init_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
		mlx_hook(mlx.win_ptr, 2, 0, key_press, &mlx);
		mlx_mouse_hook(mlx.win_ptr, mouse_press, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
		mlx_loop(mlx.init_ptr);
	}
	return (0);
}
