/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:04:14 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/21 19:40:54 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_burning_ship(t_fctl *f)
{
	double	x;
	double	y;
	int		i;

	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_W)
		{
			i = -1;
			f->real_unit = x * 0.005 - 0.2 - 2; // сюда зум и движение
			f->im_unit = y * 0.005 - 0.3 - 1.75; //
			f->n_r = 0;
			f->n_i = 0;
			while (ft_pow(f->n_r, 2) + ft_pow(f->n_i, 2) < 4 && ++i < f->max_i)
			{
				f->s_r = f->n_r;
				f->s_i = f->n_i;
				f->n_r = ft_pow(f->s_r, 2) - ft_pow(f->s_i, 2) + f->real_unit;
				f->n_i = 2 * ft_abs(f->s_r * f->s_i) + f->im_unit;
			}
			put_pix_img(f, x, y, ((50 * i % 256) << 16) | ((80 * i % 256) << 8) | (120 * i % 256));
		}
	}
}
