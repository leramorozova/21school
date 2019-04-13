/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:14:19 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/08 20:14:49 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_malloc(char ***map)
{
	int		i;

	i = 0;
	while ((*map)[i])
		ft_strdel(&((*map)[i++]));
	free(*map);
}

int			map_malloc(char ***map, int figures)
{
	int		size;
	int		i;
	char	**new_map;

	if (*map)
	{
		size = ft_strlen((*map)[0]) + 1;
		free_malloc(map);
	}
	else
		size = ft_sqrt(4 * figures);
	if (!(new_map = (char **)malloc(sizeof(*new_map) * (size + 1))))
		return (0);
	i = -1;
	while (++i < size)
	{
		if (!(new_map[i] = ft_strnew(size)))
			return (0);
		new_map[i] = ft_memset(new_map[i], '.', size);
	}
	new_map[size] = NULL;
	*map = new_map;
	return (1);
}

void		change_char(int xy[2], t_coord *coords, char ***map, char c)
{
	int	t;

	t = -1;
	while (++t < 4)
		(*map)[xy[1] + coords->y[t]][xy[0] + coords->x[t]] = c;
}

int			map_filling(t_coord **cs, char **mp, char fill)
{
	int		xy[2];
	int		t;

	if (cs && *cs && (xy[1] = -1))
	{
		while (++xy[1] <= (int)ft_strlen(mp[0]) - (*cs)->height && (xy[0] = -1))
		{
			while (++xy[0] <= (int)ft_strlen(mp[0]) - (*cs)->width && (t = -1))
			{
				while (++t < 4)
					if (mp[xy[1] + (*cs)->y[t]][xy[0] + (*cs)->x[t]] != '.')
						break ;
				if (t == 4)
				{
					change_char(xy, *cs, &mp, fill);
					if (map_filling(&((*cs)->next), mp, fill + 1))
						return (1);
					change_char(xy, *cs, &mp, '.');
				}
			}
		}
		return (0);
	}
	print_char_arr(mp);
	return (1);
}

int			try_map(int figures, t_coord **coords)
{
	char	**map;

	map = NULL;
	while (1)
	{
		if (!map_malloc(&map, figures))
			return (0);
		if (map_filling(coords, map, 'A'))
		{
			free_malloc(&map);
			break ;
		}
	}
	return (1);
}
