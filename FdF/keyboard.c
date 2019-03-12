/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:58:51 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/12 13:19:54 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_int_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void			make_z_to_y(t_mlx *mlx)
{
	int		max_height;
	int		min_height;
	t_map	*begin;

	begin = mlx->map;
	max_height = -1000;
	min_height = 1000;
	while (mlx->map)
	{
		max_height = max_height < mlx->map->z ? mlx->map->z : max_height;
		min_height = min_height > mlx->map->z ? mlx->map->z : min_height;
		ft_int_swap(&mlx->map->z, &mlx->map->y);
		mlx->map = mlx->map->next;
	}
	mlx->height = max_height - min_height;
	mlx->map = begin;
	redraw_image(mlx);
}
