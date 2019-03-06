/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:47:54 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/06 17:41:30 by sdurgan          ###   ########.fr       */
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

static void		put_line(t_mlx **mlx, t_map *dot0, t_map *dot1)
{
	float	deltax;
	float	deltay;
	float	deltaerr;
	float	error;
	t_map	*dot_cur;

	if (dot0->x == dot1->x)
		return (vertical_line(mlx, dot0->x, dot0->y, dot1->x, dot1->y));
	dot_cur = (t_map *)malloc(sizeof(t_map));
	dot_cur->x = dot0->x;
	dot_cur->y = dot0->y;
	deltax = dot1->x - dot0->x;
	deltay = dot1->y - dot0->y;
	error = 0;
	deltaerr = ft_abs(deltay / deltax);
	while (dot_cur->x != dot1->x)
	{
		(*mlx)->int_data[(int)(dot_cur->x) + (*mlx)->line_size *
			(int)(dot_cur->y)] = 0xFFFFFF;
		error += deltaerr;
		if (error >= 0.5)
		{
			dot_cur->y += ft_sign(deltay) * 1;
			error -= 1.0;
		}
		dot_cur->x++;
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
 		dot1->x *= zoom;
		dot1->y *= zoom;
		put_line(mlx, dot0, dot1);
		map = map->next;
	}
}
