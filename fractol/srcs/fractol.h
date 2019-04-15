/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:34:32 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/15 13:34:36 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL
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

typedef struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	int				color;
	struct s_pixel	*right;
	struct s_pixel	*down;
}					t_pixel;

typedef struct		s_fctl
{
    char			*title;
    void			*mlx_init;
	void			*win;
    void			*img;
    unsigned int	*int_img;
    int				img_limit;
}					t_fctl;

#endif