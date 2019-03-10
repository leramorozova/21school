/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:47:54 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/10 18:01:52 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	vertical_line(t_mlx *mlx, t_map dot0, t_map dot_cur, t_map dot1)
{
	while (dot_cur.y != dot1.y)
	{
		mlx->int_data[(int)(dot_cur.x) +
			mlx->window_x * (int)(dot_cur.y)] = 0xFFFFFF;
		dot_cur.y++;
	}
}

static void		put_line(t_mlx *mlx, t_map dot0, t_map dot1)
{
	float	deltax;
	float	deltay;
	float	deltaerr;
	float	error;
	t_map	dot_cur;

	dot_cur.x = dot0.x;
	dot_cur.y = dot0.y;
	if (!(error == 0) && dot0.x == dot1.x)
		return (vertical_line(mlx, dot0, dot_cur, dot1));
	deltax = dot1.x - dot0.x;
	deltay = dot1.y - dot0.y;
	deltaerr = ft_abs(deltay / deltax);
	while (dot_cur.x != dot1.x)
	{
		mlx->int_data[(int)(dot_cur.x) + mlx->window_x *
			(int)(dot_cur.y)] = 0xFFFFFF;
		error += deltaerr;
		if (error >= 0.5)
		{
			dot_cur.y += ft_sign(deltay) * 1;
			error -= 1.0;
		}
		dot_cur.x++;
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

static void		put_y(t_mlx *mlx, t_map *begin)
{
	t_map	dot0;
	t_map	dot1;
	t_map	*parallel;

	parallel = map_bias(begin);
	while(parallel)
 	{
		dot0.x = begin->x * mlx->zoom + mlx->offset_x;;
		dot0.y = begin->y * mlx->zoom + mlx->offset_y;
		dot1.x = parallel->x * mlx->zoom + mlx->offset_x;
		dot1.y = parallel->y * mlx->zoom + mlx->offset_y;
		put_line(mlx, dot0, dot1);
		begin = begin->next;
		parallel = parallel->next;
	}
}

void			put_map(t_mlx *mlx, t_map *map)
{
	t_map	*begin;
	t_map	dot0;
	t_map	dot1;

	begin = map;
	while(map->next)
 	{
		map = map->next && map->y == map->next->y ? map : map->next;
		dot0.x = map->x * mlx->zoom + mlx->offset_x;
		dot0.y = map->y * mlx->zoom + mlx->offset_y;
 		dot1.x = map->next->x * mlx->zoom + mlx->offset_x;
		dot1.y = map->next->y * mlx->zoom + mlx->offset_y;
		put_line(mlx, dot0, dot1);
		map = map->next;
	}
	put_y(mlx, begin);
}
