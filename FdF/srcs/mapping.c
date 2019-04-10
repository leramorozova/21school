/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:11:03 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/10 14:02:13 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			init_map(char *name)
{
	t_map	map;

	map.name = name;
	map.width = 0;
	map.height = 0;
	map.pixel = 0;
	map.scale = 0;
	map.offset_x = 0;
	map.offset_y = 0;
	map.move_x = 0;
	map.move_y = 0;
	map.change_z = 0;
	map.min_volume = 0;
	map.max_volume = 0;
	map.flatten = 0;
	return (map);
}

void			offset_x(t_map *map)
{
	t_pixel *save;
	float	min;
	float	max;

	if (map->change_z == 1)
		return ;
	save = map->pixel;
	min = map->pixel->x;
	max = map->pixel->x;
	while (map->pixel)
	{
		min = map->pixel->x < min ? map->pixel->x : min;
		max = map->pixel->x > max ? map->pixel->x : max;
		map->pixel = map->pixel->right;
	}
	map->pixel = save;
	map->offset_x = map->move_x + WIN_W / 2 - map->scale *
			(max - min) / 2;
}

void			offset_y(t_map *map)
{
	t_pixel *save;
	double	min;
	double	max;

	if (map->change_z == 1)
		return ;
	save = map->pixel;
	min = map->pixel->y;
	max = map->pixel->y;
	while (map->pixel)
	{
		min = map->pixel->y < min ? map->pixel->y : min;
		max = map->pixel->y > max ? map->pixel->y : max;
		map->pixel = map->pixel->right;
	}
	map->pixel = save;
	map->offset_y = map->move_y + WIN_H / 2 - map->scale *
			(max - min) / 2;
}

static int		autoscaling(t_map *map)
{
	int		scale;
	t_pixel	*begin;

	begin = map->pixel;
	while (map->pixel)
	{
		map->min_volume = map->pixel->z < map->min_volume ? map->pixel->z :
			map->min_volume;
		map->max_volume = map->pixel->z > map->max_volume ? map->pixel->z :
			map->max_volume;
		map->pixel = map->pixel->right;
	}
	map->pixel = begin;
	scale = (WIN_H / (map->width * 2));
	scale += scale < 3 ? 2 : 0;
	return (scale);
}

void			fill_map(t_fdf *fdf, char *name)
{
	fdf->prj = 3;
	fdf->map = init_map(name);
	fdf->map.pixel = read_map(name, fdf->map.pixel, &(fdf->map.width),
			&(fdf->map.height));
	fdf->map.flatten = copy_pixel(fdf->map.pixel);
	prj_iso(&(fdf->map));
	fdf->map.scale = autoscaling(&fdf->map);
	put_color(&(fdf->map.pixel), fdf->map.min_volume, fdf->map.max_volume);
	put_color(&(fdf->map.flatten), fdf->map.min_volume, fdf->map.max_volume);
}
