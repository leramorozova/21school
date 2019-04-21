/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:50:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/21 17:27:43 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia(t_fctl *f, int x, int y)
{
	f->n_r = 1.5 * (x - WIN_W / 2) / (f->zoom * WIN_W / 2) + f->move_x;
	f->n_i = (y - WIN_H / 2) / (f->zoom * WIN_H / 2) + f->move_y;
	f->real_unit = -0.7 + f->real_unit_change;
	f->im_unit = 0.27015 + f->im_unit_change;
}

static void	mandelbro(t_fctl *f, int x, int y)
{
	f->real_unit = 1.5 * (x - WIN_W / 2) / (f->zoom * WIN_W / 2) +
														f->move_x - 0.5;
	f->im_unit = (y - WIN_H / 2) / (f->zoom * WIN_H / 2) + f->move_y;
	f->n_r = 0;
	f->n_i = 0;
}

static void	make_mandeljulia(t_fctl *f)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIN_W && (y = f->thread_start - 1))
	{
		while (++y < f->thread_end && y < WIN_H)
		{
			!ft_strcmp(f->title, "Julia") ? julia(f, x, y) : mandelbro(f, x, y);
			i = -1;
			while (++i < f->max_iter)
			{
				f->s_r = f->n_r;
				f->s_i = f->n_i;
				f->n_r = ft_power(f->s_r, 2) - ft_power(f->s_i, 2)
					+ f->real_unit;
				f->n_i = 2 * f->s_r * f->s_i + f->im_unit;
				if ((ft_power(f->n_r, 2) + ft_power(f->n_i, 2)) > 4)
					break ;
			}
			put_pix_img(f, x, y, 265 * i);
		}
	}
}

void		*mandeljulia(void *div)
{
	t_fctl	*fctl;

	fctl = (t_fctl *)div;
	make_mandeljulia(fctl);
	return (div);
}

void	make_julia_default(t_fctl *fractol)
{
	fractol->n_r = 0.0;
	fractol->n_i = 0.0;
	fractol->max_iter = 150;
	fractol->zoom = 0.75;
	fractol->move_x = 0;
	fractol->move_y = 0;
	fractol->real_unit_change = 0;
	fractol->im_unit_change = 0;
	fractol->change_color = 0;
}
