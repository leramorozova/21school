/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:50:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/18 13:20:29 by sdurgan          ###   ########.fr       */
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

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
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
			put_pix_img(fractol, x, y, 265 * i);
			printf("%d, %d\n", x, y);
			x++;
		}
		y++;
	}
}
