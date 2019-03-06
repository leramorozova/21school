/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:04:58 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/04 17:13:23 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	position_value(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static float	percentage(float x0, float y0, float x1, float y1,
		float x_curr, float y_curr)
{
	float	percentage;
	float	deltax;
	float	deltay;

	deltax = ft_abs(x0 - x1);
	deltay = ft_abs(y0 - y1);
    if (deltax > deltay)
		percentage = position_value(x0, x1, x_curr);
	else
		percentage = position_value(y0, y1, x_curr);
	return (percentage);
}
