/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:50:43 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/17 17:06:05 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_julia(t_fctl *fractol)
{
	int		x;
	int		y;
	int		i = 0;
	int		maxIterations = 1000;
	int		color ;
	double	cRe = -0.7;
	double	cIm = 0.27015;         
	double	newRe, newIm, oldRe, oldIm;
	double	zoom = 1, moveX = 0, moveY = 0;

	y = 0;
	ft_putstr("here");
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			/*newRe = 1.5 * (x - WIN_W / 2) / (0.5 * zoom * WIN_W) + moveX;
			newIm = (y - WIN_H / 2) / (0.5 * zoom * WIN_H) + moveY;
			while (i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				if ((newRe * newRe + newIm * newIm) > 4)
					break ;
				i++;
			}
			color = get_color(i % 256, 255, 255 * (i < maxIterations));
			put_pix_img(fractol, x, y, color);
			i = 0;
			printf("%d, %d\n", x, y);*/
			x++;
		}
		y++;
	}
}
