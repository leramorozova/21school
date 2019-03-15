/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:15:48 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/15 15:53:55 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    rotate_x(int *y, int *z, double alpha)
{
    int y0;
    y0 = *y;
    *y = y0 * cos(alpha) + *z * sin(alpha);
    *z = -y0 * sin(alpha) + *z * cos(alpha);
}

void    rotate_y(int *x, int *z, double alpha)
{
    int x0;
    x0 = *x;
    *x = x0 * cos(alpha) + *z * sin(alpha);
    *z = -x0 * sin(alpha) + *z * cos(alpha);
}

void    rotate_z(int *x, int *y, double alpha)
{
    int y0;
    int x0;

    y0 = *y;
    x0 = *x;
    *x = x0 * cos(alpha) - y0 * sin(alpha);
    *y = -x0 * sin(alpha) + y0 * cos(alpha);
}

void    prj_iso(t_mlx *mlx)
{
    float 	x0;
    float 	y0;
	float		min;
	t_map	*begin;

	begin = mlx->map;
	while (mlx->map)
	{
    	x0 = mlx->map->x;
    	y0 = mlx->map->y;
    	mlx->map->x = (x0 - y0) * cos(0.523599);
    	mlx->map->y = -(mlx->map->z) + (x0 + y0) * sin(0.523599);
		min = mlx->map->x < min ? mlx->map->x : min;
		min = mlx->map->y < min ? mlx->map->y : min;
		mlx->map = mlx->map->next;
	}
	mlx->map = begin;
 	if (min < 10)
	{
		while(mlx->map)
		{
			mlx->map->x += -min;
			mlx->map->y += -min;
			mlx->map = mlx->map->next;
		}
	}
	mlx->map = begin;
}
