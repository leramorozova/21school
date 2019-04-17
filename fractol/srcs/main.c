/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:43:28 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/17 16:31:19 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_fctl *param)
{
	param = NULL;
	exit(0);
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
		make_julia(&fractol);
		draw_img(&fractol);
		mlx_hook(fractol.win, 2, 0, keyboard, &fractol);
		mlx_hook(fractol.win, 17, 0, close_window, &fractol);
		mlx_loop(fractol.mlx_init);
	}
	else
		return (write(1, "Usage: ./fractol fractol_name (e.g Julia)\n", 42));
}
