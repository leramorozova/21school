/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:47:54 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/06 15:18:05 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	vertical_line(void *mlx_ptr, void *win_ptr, float x0, float y0,
	   	float x1, float y1)
{
	while (y0 != y1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFFFFFF);
		y0++;
	}
}

void		line(t_mlx *mlx, float x0, float y0, float x1, float y1)
{
	float	deltax;
	float	deltay;
	float	deltaerr;
	float	error;

	if (x0 == x1)
		return (vertical_line(mlx->init_ptr, mlx->win_ptr, x0, y0, x1, y1));
	deltax = x1 - x0;
	deltay = y1 - y0;
	error = 0;
	deltaerr = ft_abs(deltay / deltax);
	while (x0 != x1)
	{
		mlx_pixel_put(mlx->init_ptr, mlx->win_ptr, x0, y0, 0xFFFFFF);
		error += deltaerr;
		if (error >= 0.5)
		{
			y0 += ft_sign(deltay) * 1;
			error -= 1.0;
		}
		x0++;
	}
}
