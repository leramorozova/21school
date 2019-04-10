/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:10:09 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/10 13:45:54 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W 1920
# define WIN_H 1080

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_img
{
	void			*img;
	unsigned int	*data;
	int				size_line;
	int				end;
	int				bits_per_pixel;
	int				width;
	int				height;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_init;
	int				width;
	int				height;
	char			*title;
	t_img			img;
	void			*win;
}					t_mlx;

typedef struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
	struct s_pixel	*right;
	struct s_pixel	*down;
}					t_pixel;

typedef struct		s_map
{
	char			*name;
	int				width;
	int				height;
	int				min_volume;
	int				max_volume;
	t_pixel			*pixel;
	t_pixel			*flatten;
	float			scale;
	int				offset_x;
	int				offset_y;
	int				move_x;
	int				move_y;
	int				change_z;
}					t_map;

typedef struct		s_fdf
{
	t_mlx			mlx;
	t_map			map;
	int				prj;
}					t_fdf;

t_mlx				init_mlx(void *mlx, int width, int height);
void				init_win(t_mlx *mlx, char *title, int width, int height);
void				redraw_image(t_fdf *fdf);
int					mouse(int key, int x, int y, t_fdf *param);
int					keyboard(int key, t_fdf *param);
void				fill_map(t_fdf *fdf, char *name);
void				offset_x(t_map *map);
void				offset_y(t_map *map);
void				define_colour(t_pixel *pixel, char *str);
t_pixel				init_pixel(double x, double y, double z,
		unsigned int color);
t_pixel				*copy_pixel(t_pixel *source);
int					get_color(t_pixel dot_curr, t_pixel dot0, t_pixel
		dot1, t_pixel delta);
void				put_color(t_pixel **pixel, double min_volume, double
		max_volume);
t_img				init_img(void *mlx, void *win, int width, int height);
int					draw_img(void *mlx, void *win, t_img img);
void				clear_img(t_img *img);
int					put_pix_img(void *mlx, void *mx, t_pixel p);
int					validate_map(t_map *map);
int					get_map(t_map *map);
t_map				init_map(char *name);
int					destroy_map(t_map *map);
t_pixel				*read_map(char *name, t_pixel *pixel, int *wigth,
		int *height);
void				draw_line(t_pixel f, t_pixel s, t_fdf *fdf);
void				put_map(t_map *map, t_fdf *fdf);
t_mlx				init_mlx(void *mlx, int width, int height);
void				init_win(t_mlx *mlx, char *title, int width, int height);
void				prj_iso(t_map *map);

#endif
