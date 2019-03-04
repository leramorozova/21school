/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:00:10 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/04 16:23:24 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	int				colour;
	struct s_map	*next;
}					t_map;

t_map				*read_map(char *filename, t_map *map);
void				del_map(t_map **map);
void				line(void *mlx_ptr, void *win_ptr, float x0, float y0, float x1, float y1);

#endif
