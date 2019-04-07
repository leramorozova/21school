/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:28:10 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/07 14:31:18 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_min(t_map *map, t_pixel min)
{
	t_pixel	*begin;

	begin = map->pixel;
	while (map->pixel)
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
	map->pixel = begin;
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

void		prj_iso(t_map *map)
{
	t_pixel	*begin;
	t_pixel	min;

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
		add_min(map, min);
}
