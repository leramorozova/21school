/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:50:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/22 14:59:52 by sdurgan          ###   ########.fr       */
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

static void	mandelship(t_fctl *f, int x, int y)
{
	f->real_unit = 1.5 * (x - WIN_W / 2) / (f->zoom * WIN_W / 2) +
		f->move_x - 0.5 + 0.1 * !ft_strcmp(f->title, "Sheep");
	f->im_unit = (y - WIN_H / 2) / (f->zoom * WIN_H / 2) + f->move_y
		- 0.5 * !ft_strcmp(f->title, "Sheep");
	f->n_r = 0;
	f->n_i = 0;
}

static void	make_fractol(t_fctl *f)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIN_W && (y = f->thread_start - 1))
	{
		while (++y < f->thread_end && y < WIN_H)
		{
			!ft_strcmp(f->title, "Julia") ? julia(f, x, y) : 0;
			!ft_strcmp(f->title, "Mandelbrot") ||
				!ft_strcmp(f->title, "Sheep") ? mandelship(f, x, y) : 0;
			i = -1;
			while (ft_pow(f->n_r, 2) + ft_pow(f->n_i, 2) < 4 && ++i < f->max_i)
			{
				f->s_r = f->n_r;
				f->s_i = f->n_i;
				f->n_r = ft_pow(f->s_r, 2) - ft_pow(f->s_i, 2)
					+ f->real_unit;
				f->n_i = f->im_unit + 2 * (!ft_strcmp(f->title,
					"Sheep") ? ft_abs(f->s_r * f->s_i) : f->s_r * f->s_i);
			}
			put_pix_img(f, x, y, color_schema(f, i));
		}
	}
}

void		*fractol(void *div)
{
	t_fctl	*fctl;

	fctl = (t_fctl *)div;
	make_fractol(fctl);
	return (div);
}
