/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:50:57 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/02 15:57:42 by sdurgan          ###   ########.fr       */
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
	void	*window;
	t_map	*map;

	if (argc == 2)
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
		}
	}
//	window = mlx_new_window(mlx_ptr, 500, 500, "title");
//	mlx_pixel_put(mlx_ptr, window, 250, 250, 0xFFFFFF);
//	mlx_hook(window, 2, 0, key_press, 0);
	return (0);
}
