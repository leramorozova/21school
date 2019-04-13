/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:01:59 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/08 20:14:25 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"

typedef	struct		s_coord
{
	int				x[4];
	int				y[4];
	int				height;
	int				width;
	struct s_coord	*next;
}					t_coord;

t_coord				*ft_lstadd_to_end(t_coord **coordinates);
void				ft_delcoords(t_coord **coords);
int					check_map_procession(int z[4], char *line,
										t_coord **coords);
int					check_map(int fd, char *line, t_coord **coords);
void				make_bias(t_coord **coords, int params[4]);
int					count_bias(t_coord	**coords);
int					check_figures(t_coord **cs);
void				free_malloc(char ***map);
int					map_malloc(char ***map, int figures);
void				change_char(int xy[2], t_coord *coords, char ***map,
								char c);
int					map_filling(t_coord **cs, char **mp, char fill);
int					try_map(int figures, t_coord **coords);

#endif
