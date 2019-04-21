/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:34:32 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/21 17:14:11 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_W 800
# define WIN_H 600
# define THREADS_Q 200

# include "mlx.h"
# include "libft/libft.h"
# include "math.h"
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct		s_fctl
{
	char			*title;
	void			*mlx_init;
	void			*win;
	void			*img;
	unsigned int	*int_img;
	double			zoom;
	double			move_x;
	double			move_y;
	int				max_iter;
	double			real_unit;
	double			im_unit;
	double			real_unit_change;
	double			im_unit_change;
	double			n_r;
	double			s_r;
	double			n_i;
	double			s_i;
	int				thread_start;
	int				thread_end;
	int				fix_mouse;
	int				change_color;
}					t_fctl;

typedef struct		s_thread
{
	int				size;
	pthread_t		id[THREADS_Q];
}					t_thread;


int					get_color(int red, int green, int blue);
int					draw_img(t_fctl *frac);
int					put_pix_img(t_fctl *fractol, double x, double y, int color);
int					keyboard(int key, t_fctl *fractol);
t_thread			init_thread(void);
void				make_threads(t_fctl *fctl, t_thread thread,
												void *func(void *));
int					mouse_press(int button, int x, int y, t_fctl *param);
int					mouse_move(int x, int y, t_fctl *param);
void				*julia(void *div);
void				redraw_img(t_fctl *fctl);
void				make_julia_default(t_fctl *fractol);
void				*mandelbrot(void *div);
void				make_mandelbrot(t_fctl *f);


#endif
