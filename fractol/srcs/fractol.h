/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:34:32 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/17 16:19:57 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_W 1920
# define WIN_H 1080

# include "mlx.h"
# include "libft/libft.h"
# include "math.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_img
{
	void			*img;
	unsigned int	*int_data;
	int				size_line;
	int				end;
	int				bits_per_pixel;
}					t_img;

typedef struct		s_fctl
{
	char			*title;
	void			*mlx_init;
	void			*win;
	void			*img;
	unsigned int	*int_img;
	int				img_limit;
	int				zoom;
}					t_fctl;

int					get_color(int red, int green, int blue);
int					draw_img(t_fctl *frac);
int					put_pix_img(t_fctl *fractol, double x, double y, int color);
void				make_julia(t_fctl *fractol);
int					keyboard(int key, t_fctl *fractol);

#endif
