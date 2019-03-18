/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:32:47 by sbrella           #+#    #+#             */
/*   Updated: 2019/03/18 18:12:45 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
	(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
	(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
} */

void		drawlinelow(t_mlx *mlx, t_map dot0, t_map dot1)
{
	t_delta	delta;
	t_map	dot_cur;
	int		diry;

	delta.x = ft_abs(dot0.x - dot1.x);
	delta.y = ft_abs(dot0.y - dot1.y);
	delta.x = ft_abs(dot0.y - dot1.y);
	delta.err = 0;
	diry = dot1.y - dot0.y;
	diry > 0 ? diry = 1 : 0;
	diry < 0 ? diry = -1 : 0;
	dot_cur = dot0;
	while (dot_cur.x < dot1.x)
	{
		//cord.color = color(cord, start, end, delta)
		if ((int)dot_cur.x + mlx->window_x * (int)dot_cur.y < mlx->edge &&
				(int)dot_cur.x + mlx->window_x * (int)dot_cur.y >= 0)
			mlx->int_data[(int)dot_cur.x + mlx->window_x * (int)dot_cur.y] = 0xFFFFFF;
		delta.err += delta.z;
		if (2 * delta.err >= delta.x)
		{
			dot_cur.y += diry;
			delta.err -= delta.x;
		}
		dot_cur.x++;
	}
	printf("your: %g, how it should be: %g\n", dot_cur.y, dot1.y);
	printf("your: %g, how it should be: %g\n", dot_cur.x, dot1.x);
}

void		drawlinehight(t_mlx *mlx, t_map dot0, t_map dot1)
{
	t_delta	delta;
	t_map	dot_cur;
	int		dirx;

	delta.x = ft_abs(dot0.x - dot1.x);
	delta.y = ft_abs(dot0.y - dot1.y);
	delta.z = ft_abs(dot0.x - dot1.x);
	delta.err = 0;
	dirx = dot1.x - dot0.x;
	dirx > 0 ? dirx = 1 : 0;
	dirx < 0 ? dirx = -1 : 0;
	dot_cur = dot0;
	while (dot_cur.y < dot1.y)
	{
		//dot_cur.color = color(cord, start, end, delta);
		if ((int)dot_cur.x + mlx->window_x * (int)dot_cur.y < mlx->edge &&
				(int)dot_cur.x + mlx->window_x * (int)dot_cur.y >= 0)
			mlx->int_data[(int)dot_cur.x + mlx->window_x * (int)dot_cur.y] = 0xFFFFFF;
		delta.err = delta.err + delta.z;
		if (2 * delta.err >= delta.x)
		{
			dot_cur.x += dirx;
			delta.err -= delta.y;
		}
		dot_cur.y++;
	}
	printf("your: %g, how it should be: %g\n", dot_cur.x, dot1.x);
	printf("your: %g, how it should be: %g\n", dot_cur.y, dot1.y);
}

void		drawline(t_mlx *mlx, t_map dot0, t_map dot1)
{
	if (ft_abs(dot1.y - dot0.y) < ft_abs(dot1.x - dot0.x))
	{
		if (dot0.x > dot1.x)
			drawlinelow(mlx, dot1, dot0);
		else
			drawlinelow(mlx, dot0, dot1);
	}
	else
	{
		if (dot0.y > dot1.y)
			drawlinehight(mlx, dot1, dot0);
		else
			drawlinehight(mlx, dot0, dot1);
	}
}
