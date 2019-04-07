/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:32:51 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/07 15:47:36 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(double start, double end, double current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		count_color(double p)
{
	int		red;
	int		green;
	int		blue;

	red = get_light((0x00FE7A >> 16) & 0xFF, (0xFE4900 >> 16) & 0xFF, p);
	green = get_light((0x00FE7A >> 8) & 0xFF, (0xFE4900 >> 8) & 0xFF, p);
	blue = get_light(0x00FE7A & 0xFF, 0xFE4900 & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}

void			put_color(t_pixel **pixel, double min, double max)
{
	t_pixel *begin;

	begin = *pixel;
	while (*pixel)
	{
		if ((*pixel)->color == 0)
		{
			(*pixel)->z == max ? (*pixel)->color = 0xFE4900 : 0;
			if ((*pixel)->z == min)
				(*pixel)->color = 0x00FE7A;
			else
				(*pixel)->color = count_color(percent(min, max, (*pixel)->z));
		}
		if ((*pixel)->down && (*pixel)->down->color == 0)
		{
			(*pixel)->down->z == max ? (*pixel)->down->color = 0xFE4900 : 0;
			if ((*pixel)->down->z == min)
				(*pixel)->down->color = 0x00FE7A;
			else
				(*pixel)->down->color =
					count_color(percent(min, max, (*pixel)->down->z));
		}
		*pixel = (*pixel)->right;
	}
	*pixel = begin;
}

int				get_color(t_pixel dot_curr, t_pixel dot0, t_pixel dot1,
		t_pixel delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (dot_curr.color == dot1.color)
		return (dot_curr.color);
	if (delta.x > delta.y)
		percentage = percent(dot0.x, dot1.x, dot_curr.x);
	else
		percentage = percent(dot0.y, dot1.y, dot_curr.y);
	red = get_light((dot0.color >> 16) & 0xFF, (dot1.color >> 16) & 0xFF,
			percentage);
	green = get_light((dot0.color >> 8) & 0xFF, (dot1.color >> 8) & 0xFF,
			percentage);
	blue = get_light(dot0.color & 0xFF, dot1.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
