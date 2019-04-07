/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:14:33 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/06 15:10:16 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel		init_pixel(double x, double y, double z, unsigned int color)
{
    t_pixel pix;

	pix.x = x;
    pix.y = y;
    pix.z = z;
    pix.color = color;
    return (pix);
}

void		copy_point(t_pixel *source, t_pixel *copy)
{
	copy->x = source->x;
	copy->y = source->y;
	copy->z = source->z;
	copy->color = source->color;
}

t_pixel		*copy_pixel(t_pixel *source)
{
	t_pixel		*begin_source;
	t_pixel		*begin_copy;
	t_pixel		*copy;

	begin_source = source;
	copy = (t_pixel *)malloc(sizeof(t_pixel));
	begin_copy = copy;
	copy_point(source, copy);
	while (source)
	{
		if (source->right)
		{
			copy->right = (t_pixel *)malloc(sizeof(t_pixel));
			copy_point(source->right, copy->right);
		}
		if (source->down)
		{
			copy->down = (t_pixel *)malloc(sizeof(t_pixel));
			copy_point(source->down, copy->down);
		}
		copy = copy->right;
		source = source->right;
	}
	source = begin_source;
	return (begin_copy);
}

