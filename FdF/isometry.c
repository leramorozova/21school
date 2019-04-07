/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:28:10 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/06 15:01:05 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pixel.h"
//#include "mapping.h"
//#include <math.h>
//#include <stdio.h>
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

static void	change_params(double *x, double *y, double z, t_pixel *min)
{
	double x0;
	double y0;

	x0 = *x;
	y0 = *y;
	*x = (x0 - y0) * cos(0.523599);
	*y = -z + (x0 + y0) * sin(0.523599);
	min->x = *x < min->x ? *x : min->x;
	min->y = *y < min->y ? *y : min->y;
}

void    	prj_iso(t_map *map)
{
	t_pixel	*begin;
	t_pixel	 min;

	begin = map->pixel;
	min = init_pixel(0, 0, 0, 0);
	while (map->pixel)
	{
		change_params(&(map->pixel->x), &(map->pixel->y), map->pixel->z, &min);
		if (map->pixel->down)
			change_params(&(map->pixel->down->x), &(map->pixel->down->y),
					 map->pixel->down->z, &min);
		map->pixel = map->pixel->right;
	}
	map->pixel = begin;
	if (min.x < 0 || min.y < 0)
	{
		while(map->pixel)
		{
			if (map->pixel->down)
			{
				map->pixel->down->x += min.x < 0 ? -min.x : 0;
				map->pixel->down->y += min.y < 0 ? -min.y : 0;
			}
			map->pixel->x += min.x < 0 ? -min.x : 0;
			map->pixel->y += min.y < 0 ? -min.y : 0;
			map->pixel = map->pixel->right;
		}
	}
	map->pixel = begin;
}