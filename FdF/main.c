/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:50:57 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/04 16:43:45 by sdurgan          ###   ########.fr       */
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
	(void)param;
	exit(0);
	return (0);
}

int		key_press(int key, void *param)
{
	if (key == 53)
		close_window(0);
	if (key == 18)
		ft_putchar('X');
	if (key == 19)
		ft_putchar('y');
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_map	*map;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "test");
	line(mlx_ptr, mlx_win, 250, 0, 250, 500);
	mlx_hook(mlx_win, 2, 0, key_press, 0);
	mlx_hook(mlx_win, 17, 0, close_window, 0);
	mlx_loop(mlx_ptr);
/* 	if (argc == 2)
	{
		map = NULL;
		map = read_map(argv[1], map);
		if (map)
		{
			del_map(&map);
			//mlx_ptr = mlx_init();
			//чтобы окно закрывалось на крестик
			//mlx_hook(window, 17, 0, close_window, 0);
			//mlx_loop(mlx_ptr);
			mlx_destroy_window(mlx_ptr, window);
		}
	} */
	return (0);
}
