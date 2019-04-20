/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:50:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/20 11:26:50 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_julia(t_fctl *f)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIN_W && (y = f->thread_start - 1))
	{
		while (++y < f->thread_end && y < WIN_H)
		{
			f->n_r = 1.5 * (x - WIN_W / 2) / (f->zoom * WIN_W / 2) + f->move_x;
			f->n_i = (y - WIN_H / 2) / (f->zoom * WIN_H / 2) + f->move_y;
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

void	*julia(void *div)
{
	t_fctl	*fctl;

	fctl = (t_fctl *)div;
	make_julia(fctl);
	return (div);
}
