/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:10:35 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/22 17:46:59 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			put_pix_img(t_fctl *fractol, double x, double y, int color)
{
	if (y < WIN_H && y > -1 && x < WIN_W && x > -1)
		fractol->int_img[(int)y * WIN_W + (int)x] = color;
	return (0);
}

void		redraw_img(t_fctl *fctl)
{
	t_thread	thread;
	int			size_line;
	int			end;
	int			bits_per_pixel;

	thread = init_thread();
	mlx_destroy_image(fctl->mlx_init, fctl->img);
	fctl->img = mlx_new_image(fctl->mlx_init, WIN_W, WIN_H);
	fctl->int_img = (unsigned int *)mlx_get_data_addr(fctl->img,
					&bits_per_pixel, &size_line, &end);
	make_threads(fctl, thread, fractol);
	draw_img(fctl);
}

int			draw_img(t_fctl *frac)
{
	int		x;
	int		y;
	char	*iterations;

	x = -1;
	y = -1;
	mlx_put_image_to_window(frac->mlx_init, frac->win, frac->img, 0, 0);
	mlx_string_put(frac->mlx_init, frac->win, 5, 1, 0xFFFFFF,
		"Iterations:\n");
	iterations = ft_itoa(frac->max_i);
	mlx_string_put(frac->mlx_init, frac->win, 125, 1, 0xFFFFFF,
		iterations);
	ft_strdel(&iterations);
	return (0);
}

t_thread	init_thread(void)
{
	t_thread	trd;

	trd.size = WIN_H / THREADS_Q;
	return (trd);
}

void		make_threads(t_fctl *fctl, t_thread thread, void *func(void *))
{
	t_fctl		div_fctl[THREADS_Q];
	int			i;

	i = 0;
	while (i < THREADS_Q)
	{
		ft_memcpy((void*)&div_fctl[i], (void*)fctl, sizeof(t_fctl));
		div_fctl[i].thread_start = thread.size * i;
		div_fctl[i].thread_end = thread.size * (i + 1);
		pthread_create(&(thread.id[i]), NULL, func, &div_fctl[i]);
		i++;
	}
	while (i--)
		pthread_join(thread.id[i], NULL);
	mlx_put_image_to_window(fctl->mlx_init, fctl->win,
				fctl->img, 0, 0);
}
