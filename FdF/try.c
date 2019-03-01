/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:50:57 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/01 19:53:03 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"

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

int		main(void)
{
	void	*mlx_ptr;
	void	*window;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 500, 500, "title");
	mlx_pixel_put(mlx_ptr, window, 250, 250, 0xFFFFFF);
	///mlx_key_hook(window, deal_key, (void *)0);
	mlx_hook(window, 2, 0, key_press, 0);
	//чтобы окно закрывалось на крестик
	mlx_hook(window, 17, 0, close_window, 0);
	mlx_loop(mlx_ptr);
}
