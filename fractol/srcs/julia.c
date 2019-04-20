/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:50:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/20 08:48:01 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_julia(t_fctl *fractol)
{
	int		x;
	int		y;
	int		i;
	double	cRe = -0.7;
	double	cIm = 0.27015;         
	double	newRe, newIm, oldRe, oldIm;

	x = 0;
	while (x < WIN_W)
	{
		y = fractol->thread_start;
		while (y < fractol->thread_end && y < WIN_H)
		{
			newRe = 1.5 * (x - WIN_W / 2) / (0.5 * fractol->zoom * WIN_W) +
				fractol->move_x;
			newIm = (y - WIN_H / 2) / (0.5 * fractol->zoom * WIN_H) +
				fractol->move_y;
			i = 0;
			while (i < fractol->max_iter)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				if ((newRe * newRe + newIm * newIm) > 4)
					break ;
				i++;
			}
			put_pix_img(fractol, x, y, 265 * i - 100);
			y++;
		}
		x++;
	}
}

void	*julia(void *div)
{
	t_fctl	*fctl;

	fctl = (t_fctl *)div;
	//printf("%d; %d\n", fctl->thread_start, fctl->thread_end);
	make_julia(fctl);
	return (div);
}

void	julia_pthread(t_fctl *fctl, t_thread thread)
{
	t_fctl		div_fctl[THREADS_Q];
	int			i;

	i = 0;
	while (i < THREADS_Q)
	{
		ft_memcpy((void*)&div_fctl[i], (void*)fctl, sizeof(t_fctl));
		div_fctl[i].thread_start = thread.size * i;
		div_fctl[i].thread_end = thread.size * (i + 1);
		pthread_create(&(thread.id[i]), NULL, julia, &div_fctl[i]);
		i++;
	}
	while (i--)
		pthread_join(thread.id[i], NULL);
	mlx_put_image_to_window(fctl->mlx_init, fctl->win,
				fctl->img, 0, 0);
}