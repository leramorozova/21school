/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:04:58 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/14 13:20:41 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * Тут ничего интересного, просто градиент по алгоритму из кукбука
 * */

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_map dot_curr, t_map dot0, t_map dot1, t_delta delta)
{
	int     red;
	int     green;
	int     blue;
	double  percentage;

	if (dot_curr.colour == dot1.colour)
		return (dot_curr.colour);
	if (delta.x > delta.y)
		percentage = percent(dot0.x, dot1.x, dot_curr.x);
	else
        percentage = percent(dot0.y, dot1.y, dot_curr.y);
	red = get_light((dot0.colour >> 16) & 0xFF, (dot1.colour >> 16) & 0xFF, percentage);
	green = get_light((dot0.colour >> 8) & 0xFF, (dot1.colour >> 8) & 0xFF, percentage);
	blue = get_light(dot0.colour & 0xFF, dot1.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
