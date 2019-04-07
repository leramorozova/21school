/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:56:17 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/07 15:47:38 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	barely_equals(double c, double b)
{
	double a;

	a = c - b;
	return (((a < 0.) ? -a : a) < 1);
}

void		draw_line(t_pixel a, t_pixel b, t_fdf *fdf)
{
	t_pixel	delta;
	t_pixel	sign;
	t_pixel	cur;
	int		error[2];

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (!barely_equals(cur.x, b.x) || !barely_equals(cur.y, b.y))
	{
		cur.color = get_color(cur, a, b, delta);
		put_pix_img(fdf->mlx.mlx_init, fdf, cur);
		if ((error[1] = error[0] << 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		error[1] < delta.x ? cur.y += sign.y : 0;
		error[1] < delta.x ? error[0] += delta.x : 0;
	}
}

static int	make_offset(t_fdf *fdf, t_map *map, int count)
{
	t_pixel		dot0;
	t_pixel		dot1;

	if (map->pixel->right && map->pixel->down && count + 1 == map->width)
	{
		dot0 = init_pixel(map->pixel->x * map->scale + map->offset_x,
				map->pixel->y * map->scale + map->offset_y,
				map->pixel->down->z, map->pixel->down->color);
		dot1 = init_pixel(map->pixel->down->x * map->scale + map->offset_x,
				map->pixel->down->y * map->scale + map->offset_y,
				map->pixel->down->z, map->pixel->down->color);
		draw_line(dot0, dot1, fdf);
		map->pixel = map->pixel->right;
		count = 1;
	}
	else
		count++;
	return (count);
}

static void	put_map_processing(t_map *map, t_fdf *fdf)
{
	t_pixel		dot0;
	t_pixel		dot1;

	dot0 = init_pixel(map->pixel->x * map->scale + map->offset_x,
				map->pixel->y * map->scale + map->offset_y, map->pixel->z,
				map->pixel->color);
	dot1 = init_pixel(map->pixel->right->x * map->scale + map->offset_x,
			map->pixel->right->y * map->scale + map->offset_y,
				map->pixel->right->z, map->pixel->right->color);
	draw_line(dot0, dot1, fdf);
	if (map->pixel->down)
	{
		dot1 = init_pixel(map->pixel->down->x * map->scale + map->offset_x,
				map->pixel->down->y * map->scale + map->offset_y,
				map->pixel->down->z, map->pixel->down->color);
		draw_line(dot0, dot1, fdf);
	}
}

void		put_map(t_map *map, t_fdf *fdf)
{
	t_pixel		*begin;
	int			count;
	t_pixel		single;

	begin = map->pixel;
	offset_x(map);
	offset_y(map);
	count = 0;
	if (!map->pixel->right)
	{
		single = init_pixel(map->pixel->x * map->scale + map->offset_x,
				map->pixel->y * map->scale + map->offset_y, map->pixel->z,
				0x00FE7A);
		put_pix_img(fdf->mlx.mlx_init, fdf, single);
	}
	while (map->pixel->right)
	{
		count = make_offset(fdf, map, count);
		put_map_processing(map, fdf);
		map->pixel = map->pixel->right;
	}
	map->pixel = begin;
}
