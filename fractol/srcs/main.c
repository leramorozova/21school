/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:43:28 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/15 13:43:39 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_fctl *param)
{
	param = NULL;
	exit(0);
}

int			main(int argc, char **argv)
{
	t_fctl	fractol;

	if (argc == 2)
	{
        printf("%s", argv[1]);
		//fill_map(&fdf, argv[1]);
		init_mlx(&fractol, argv[1]);
		init_win(&fractol.mlx, fractol.map.name);
		fractol.mlx.img = init_img(fractol.mlx.mlx_init, fractol.mlx.width,
				fractol.mlx.height);
		//put_map(&fdf.map, &fdf);
		draw_img(fractol.mlx.mlx_init, fractol.mlx.win, fractol.mlx.img);
		//mlx_hook(fractol.mlx.win, 4, 0, mouse, &fdf);
		//mlx_hook(fdf.mlx.win, 2, 0, keyboard, &fdf);
		mlx_hook(fractol.mlx.win, 17, 0, close_window, &fractol);
		mlx_loop(fractol.mlx.mlx_init);
	}
	else
		return (write(1, "Usage: ./fractol fractol_name (e.g julia)\n", 42));
}