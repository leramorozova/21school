/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:37:13 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/10 14:05:26 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx			init_mlx(void *mlx, int width, int height)
{
	t_mlx	mx;

	mx.mlx_init = mlx;
	mx.width = width;
	mx.height = height;
	return (mx);
}

void			define_colour(t_pixel *pixel, char *str)
{
	char	**row;

	if (ft_strchr(str, ','))
	{
		row = ft_strsplit(str, ',');
		pixel->z = ft_atoi(row[0]);
		pixel->color = ft_atoi_base(row[1], 16);
		ft_delarr(&row);
	}
	else
	{
		pixel->z = ft_atoi(str);
		pixel->color = -1;
	}
}

void			init_win(t_mlx *mlx, char *title, int width, int height)
{
	mlx->title = title;
	mlx->win = mlx_new_window(mlx->mlx_init, mlx->width, mlx->height,
			mlx->title);
}

static void		zoom(int key, int x, int y, t_fdf *param)
{
	if (key == 4)
	{
		if (param->map.scale > 700)
			return ;
		if (param->map.scale > 30)
			param->map.scale += 2;
		else if (param->map.scale > 300)
			param->map.scale += 6;
		param->map.scale += 2;
		redraw_image(param);
	}
	else if (key == 5)
	{
		if (param->map.scale - 2 < 1)
			return ;
		if (param->map.scale > 30)
			param->map.scale -= 2;
		else if (param->map.scale > 300)
			param->map.scale -= 6;
		param->map.scale -= 2;
		redraw_image(param);
	}
}

int				mouse(int key, int x, int y, t_fdf *param)
{
	if (key == 4 || key == 5)
		zoom(key, x, y, param);
	return (0);
}
