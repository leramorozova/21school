/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:47:54 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/10 13:22:28 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	vertical_line(t_mlx *mlx, t_map *dot0, t_map *dot_cur, t_map *dot1)
{
	while (dot_cur->y != dot1->y)
	{
		mlx->int_data[(int)(dot_cur->x) +
			mlx->line_size * (int)(dot_cur->y)] = 0xFFFFFF;
		dot_cur->y++;
	}
}

static void		put_line(t_mlx *mlx, t_map *dot0, t_map *dot1)
{
	float	deltax;
	float	deltay;
	float	deltaerr;
	float	error;
	t_map	*dot_cur;

	dot_cur = (t_map *)malloc(sizeof(t_map));
	dot_cur->x = dot0->x;
	dot_cur->y = dot0->y;
	if (dot0->x == dot1->x)
		return (vertical_line(mlx, dot0, dot_cur, dot1));
	deltax = dot1->x - dot0->x;
	deltay = dot1->y - dot0->y;
	error = 0;
	deltaerr = ft_abs(deltay / deltax);
	while (dot_cur->x != dot1->x)
	{
		mlx->int_data[(int)(dot_cur->x) + mlx->line_size *
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

static t_map	*map_bias(t_map *map)
{
	int		save;
	t_map	*ret;
	t_map	*begin;

	save = map->y;
	while (map && map->y == save)
		map = map->next;
	save = map->y;
	ret = NULL;
	begin = NULL;
	while (map)
	{
		ret = add_dot(&ret);
		if (begin == NULL)
			begin = ret;
		ret->x = map->x;
		ret->y = map->y;
		ret->z = map->z;
		map = map->next;
	}
	return (begin);
}

static void		put_y(t_mlx *mlx, t_map *begin, int zoom)
{
	t_map	*dot0;
	t_map	*dot1;
	t_map	*parallel;

	parallel = map_bias(begin);
	while(parallel)
 	{
		dot0 = begin;
		dot1 = parallel;
		dot0->x *= zoom;
		dot0->y *= zoom;
		dot1->x *= zoom;
		dot1->y *= zoom;
		put_line(mlx, dot0, dot1);
		begin = begin->next;
		parallel = parallel->next;
	}
}

void			put_map(t_mlx *mlx, t_map *map, int zoom)
{
	t_map	*begin;
	t_map	*dot0;
	t_map	*dot1;

	begin = map;
	while(map->next)
 	{
		map = map->y == map->next->y ? map : map->next;
		dot0 = (t_map *)malloc(sizeof(t_map));
		dot0->x = map->x * zoom;
		dot0->y = map->y * zoom;
		dot1 = (t_map *)malloc(sizeof(t_map));
 		dot1->x = map->next->x * zoom;
		dot1->y = map->next->y * zoom;
		put_line(mlx, dot0, dot1);
		map = map->next;
	}
	put_y(mlx, begin, zoom);
}
