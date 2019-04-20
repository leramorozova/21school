/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:34:32 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/20 09:05:42 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_W 1920
# define WIN_H 1080
# define THREADS_Q 20

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
	int				img_limit;
	double			zoom;
	int				move_x;
	int				move_y;
	int				max_iter;
	double			real_unit;
	double			im_unit;
	double			n_r;
	double			s_r;
	double			n_i;
	double			s_i;
	int				thread_start;
	int				thread_end;
}					t_fctl;

typedef struct		s_thread
{
	int				size;
	pthread_t		id[THREADS_Q];
}					t_thread;


int					get_color(int red, int green, int blue);
int					draw_img(t_fctl *frac);
int					put_pix_img(t_fctl *fractol, double x, double y, int color);
void				make_julia(t_fctl *fctl);
int					keyboard(int key, t_fctl *fractol);
t_thread			init_thread(void);
void				julia_pthread(t_fctl *fctl, t_thread thread);


#endif
