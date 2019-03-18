/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:47:54 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/18 18:17:03 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// алгоритм следующей функции не справляется с вертикальными линиями,
// это дополнение к нему
static void	vertical_line(t_mlx *mlx, t_map dot0, t_map dot1)
{
	t_map	dot_cur;

	dot_cur.x = dot0.x;
	dot_cur.y = dot0.y;
	while (dot_cur.y < dot1.y)
	{
		if ((dot_cur.x + mlx->window_x * dot_cur.y < mlx->edge) &&
				(dot_cur.x + mlx->window_x * dot_cur.y) >= 0)
			mlx->int_data[(int)dot_cur.x + mlx->window_x * (int)dot_cur.y] = 0xFFFFFF;
		dot_cur.y++;
	}
}

// рисование линии без сглаживания с защитой от рисования точки за пределами карты
void		put_line(t_mlx *mlx, t_map dot0, t_map dot1)
{
	t_delta	delta;
	float	error;
	t_map	dot_cur;

	dot_cur.y = dot0.y;
	if (dot0.x == dot1.x)
		return (vertical_line(mlx, dot0, dot1));
	delta.x = dot1.x - dot0.x;
	delta.y = dot1.y - dot0.y;
	delta.err = ft_abs(delta.y / delta.x);
	error = 0.0;
	while (dot0.x++ < dot1.x)
	{
		if (dot0.x + mlx->window_x * (dot_cur.y) < mlx->edge &&
				(dot0.x + mlx->window_x * dot_cur.y) >= 0)
			mlx->int_data[(int)dot0.x + mlx->window_x * (int)dot_cur.y] = 0xFFFFFF;
		error += delta.err;
		if (error >= 0.5)
		{
			dot_cur.y = dot_cur.y + ft_sign(delta.y) * delta.err;
			error -= 1.0;
		}
	}
}

// тут собственно делается параллельная структура для следующей функции
static t_map	*map_bias(t_map *map, int width)
{
	int		i;
	t_map	*ret;
	t_map	*begin;

	i = 0;
	while (i < width)
	{
		map = map->next;
		i++;
	}
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

/*
 * Эта функция рисует вертикальные линии. Здесь создается вторая структура с картой,
 * которая идентична изначальной, но сдвинута на второй ряд по Y. Двигаюсь по
 * двум структурам одновременно и соединяю вертикальные точки.
 */
static void		put_y(t_mlx *mlx, t_map *begin)
{
	t_map	dot0;
	t_map	dot1;
	t_map	*parallel;

	parallel = map_bias(begin, mlx->width);
	while(parallel)
 	{
		dot0.x = begin->x * mlx->zoom;// + mlx->offset_x;;
		dot0.y = begin->y * mlx->zoom;// + mlx->offset_y;
		dot1.x = parallel->x * mlx->zoom;// + mlx->offset_x;
		dot1.y = parallel->y * mlx->zoom;// + mlx->offset_y;
		if (dot1.x < dot0.x)
			put_line(mlx, dot1, dot0);
		else
			put_line(mlx, dot0, dot1);
		begin = begin->next;
		parallel = parallel->next;
	}
}

/* Конечная функция, рисующая карту - сначала она соединяет точки по горизонтали,
 * а потом - по вертикали. Параллельно все сдвигается на посчитанный заранее оффсет
 * с учетом зума. Дефолтный зум тоже от размера карты зависит
 */
void			put_map(t_mlx *mlx, t_map *map)
{
	t_map	*begin;
	t_map	dot0;
	t_map	dot1;
	int		count;

	prj_iso(mlx);
	begin = map;
	count = 1;
	mlx->zoom = 30.0;
	while(map->next)
 	{
		if (count == mlx->width && (count = 1))
			map = map->next;
		count++;
		dot0.x = map->x * mlx->zoom;//+ mlx->offset_x;
		dot0.y = map->y * mlx->zoom; //+ mlx->offset_y;
 		dot1.x = map->next->x * mlx->zoom;// + mlx->offset_x;
		dot1.y = map->next->y * mlx->zoom;// + mlx->offset_y;
		dot1.x < dot0.x ? put_line(mlx, dot1, dot0) : put_line(mlx, dot0, dot1);
		map = map->next;
	}
	put_y(mlx, begin);
}
