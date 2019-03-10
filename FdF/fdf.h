/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:00:10 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/10 13:20:57 by sdurgan          ###   ########.fr       */
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

typedef struct		s_mlx
{
	t_map			*map;
	void			*init_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_data;
	int				*int_data;
	int				line_size;
	int				zoom;
}					t_mlx;


t_map				*add_dot(t_map **map);
t_map				*read_map(char *filename, t_map *map);
void				del_map(t_map **map);
//void				put_line(t_mlx **mlx, float x0, float y0, float x1, float y1);
void				put_map(t_mlx *mlx, t_map *map, int zoom);

#endif
