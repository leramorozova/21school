/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:10:35 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/20 11:07:52 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_thread		init_thread(void)
{
	t_thread	trd;

	trd.size = WIN_H / THREADS_Q;
	return (trd);
}

int			put_pix_img(t_fctl *fractol, double x, double y, int color)
{
	if (y < WIN_H && y > -1 && x < WIN_W && x > -1)
		fractol->int_img[(int)y * WIN_W + (int)x] = color;
	return (0);
}

int			draw_img(t_fctl *frac)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	mlx_put_image_to_window(frac->mlx_init, frac->win, frac->img, 0, 0);
	/*while (++x != 361)
	{
		while (++y != 141)
			y == 140 || x == 360 ? mlx_pixel_put(frac->mlx_init, frac->win,
				x, y, 0xFFFFFF) : mlx_pixel_put(frac->mlx_init, frac->win,
					x, y, 0x000000);
		y = -1;
	}
	mlx_string_put(frac->mlx_init, frac->win, 10, 5, 0xFFFFFF,
		"There will bw some signs later\n");*/
	return (0);
}

void	make_threads(t_fctl *fctl, t_thread thread, void *func(void *))
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
