/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:47:54 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/06 17:12:02 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	vertical_line(t_mlx **mlx, float x0, float y0, float x1, float y1)
{
	while (y0 != y1)
	{
		(*mlx)->int_data[(int)x0 + (*mlx)->line_size * (int)y0] = 0xFFFFFF;
		y0++;
	}
}

static void		put_line(t_mlx **mlx, float x0, float y0, float x1, float y1)
{
	float	deltax;
	float	deltay;
	float	deltaerr;
	float	error;

	if (x0 == x1)
		return (vertical_line(mlx, x0, y0, x1, y1));
	deltax = x1 - x0;
	deltay = y1 - y0;
	error = 0;
	deltaerr = ft_abs(deltay / deltax);
	while (x0 != x1)
	{
		(*mlx)->int_data[(int)x0 + (*mlx)->line_size * (int)y0] = 0xFFFFFF;
		error += deltaerr;
		if (error >= 0.5)
		{
			y0 += ft_sign(deltay) * 1;
			error -= 1.0;
		}
		x0++;
	}
}

void			put_map(t_mlx **mlx, t_map *map, int zoom)
{
	t_map	*begin;
	t_map	*dot0;
	t_map	*dot1;

	begin = map;
	while(map->next)
	{
		dot0 = map;
		dot1 = map->next;
		put_line()
		map = map->next;
	}
}
