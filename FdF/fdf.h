/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:00:10 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/15 15:54:23 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct		s_map // карта, вроде, все очевидно
{
	float			x;
	float			y;
	float			z;
	int 			colour;
	struct s_map	*next;
}					t_map;

typedef struct		s_delta // структура для экономии переменных для рисования линий
{							//  и градиента
	float			x;
	float			y;
	float			err;
}					t_delta;

typedef struct		s_mlx // основная структура, которая содержит всю возможную инфу
{
	t_map			*map; // карта тут
	void			*init_ptr; // всякая ерунда для инифиализации
	void			*win_ptr;
	void			*img_ptr;
	void			*img_data;
	int				*int_data;
	int				zoom;
	int				width; // ширина карты
	int				height; //  высота карты
	int				volume; // выпуклость карты (типа высота по z)
	int				window_x; // размер окна (для инициализации)
	int				window_y; // размер окна (для инициализации)
	int				offset_x; // переменная для рассчета смещения по х (для центрирования)
	int				offset_y; // переменная для рассчета смещения по y (для центрирования)
	int				edge;  // количество пикселей в изображении (для защиты зума0
}					t_mlx;


t_map				*add_dot(t_map **map);
t_map				*read_map(char *filename, t_map *map, t_mlx *mlx);
void				del_map(t_map **map);
void				put_map(t_mlx *mlx, t_map *map);
int					close_window(t_mlx *param);
int					mouse_press(int key, int x, int y, t_mlx *param);
void				redraw_image(t_mlx *mlx);
int					get_color(t_map dot_curr, t_map dot0, t_map dot1,
		t_delta delta);
void				put_line(t_mlx *mlx, t_map dot0, t_map dot1);
void				make_z_to_y(t_mlx *mlx);
void				prj_iso(t_mlx *mlx);

#endif
