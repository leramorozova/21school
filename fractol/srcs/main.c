/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:43:28 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/22 15:40:52 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_fctl *param)
{
	param = NULL;
	exit(0);
}

void		make_fractol_default(t_fctl *fractol)
{
	fractol->n_r = 0.0;
	fractol->n_i = 0.0;
	fractol->max_i = 100;
	fractol->zoom = 0.75;
	fractol->move_x = 0;
	fractol->move_y = 0;
	fractol->real_unit_change = 0;
	fractol->im_unit_change = 0;
	fractol->change_color = 0;
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
	fractol->fix_mouse = 0;
	make_fractol_default(fractol);
}

int			main(int argc, char **argv)
{
	t_fctl		f;
	t_thread	thread;

	if (argc == 2)
	{
		init_mlx(&f, argv[1]);
		thread = init_thread();
		if (!ft_strcmp(argv[1], "Julia") || !ft_strcmp(argv[1], "Mandelbrot")
					|| !ft_strcmp(argv[1], "Sheep"))
			make_threads(&f, thread, fractol);
		else
			exit(ft_putstr("Invalid fractol name!\n"));
		draw_img(&f);
		mlx_hook(f.win, 2, 0, keyboard, &f);
		mlx_hook(f.win, 4, 0, mouse_press, &f);
		mlx_hook(f.win, 6, 0, mouse_move, &f);
		mlx_hook(f.win, 17, 0, close_window, &f);
		mlx_loop(f.mlx_init);
	}
	else
		return (write(1, "Usage: ./fractol fractol_name (e.g Julia)\n", 42));
}
