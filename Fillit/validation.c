/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:06:29 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/08 20:14:30 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_map_processing(int z[4], char **line, t_coord **coords)
{
	while (z[1] != 4 && ++z[0] < 4)
	{
		if ((*line)[z[0]] != '#' && (*line)[z[0]] != '.')
			return (0);
		else if ((*line)[z[0]] == '.')
			continue ;
		if (++z[2] && z[2] > 4)
			return (0);
		(*coords)->x[z[2] - 1] = z[0];
		(*coords)->y[z[2] - 1] = z[1];
	}
	if (++z[1] == 5 && !(z[1] = 0) && z[2] < 4)
	{
		ft_strdel(line);
		return (0);
	}
	ft_strdel(line);
	return (1);
}

int			check_map(int fd, char *line, t_coord **coords)
{
	int			z[4];
	t_coord		*end;

	z[1] = 0;
	while ((z[3] = get_next_line(fd, &line)) > 0)
	{
		if ((z[1] == 0 && !(z[2] = 0) &&
	!(end = ft_lstadd_to_end(coords))) || ((z[1] < 4 && ft_strlen(line) != 4)
	|| (z[1] == 4 && ft_strlen(line))))
		{
			ft_strdel(&line);
			return (-1);
		}
		z[0] = -1;
		if (!check_map_processing(z, &line, &end))
			return (-1);
	}
	if (z[1] != 4 || z[2] != 4)
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (z[3]);
}

void		make_bias(t_coord **coords, int params[4])
{
	int		i;

	(*coords)->height = params[1] - params[0] + 1;
	(*coords)->width = params[3] - params[2] + 1;
	i = -1;
	while (++i < 4)
	{
		(*coords)->y[i] -= params[0];
		(*coords)->x[i] -= params[2];
	}
	*coords = (*coords)->next;
}

int			count_bias(t_coord **coords)
{
	t_coord		*init;
	int			i;
	int			count;
	int			params[4];

	init = *coords;
	count = 0;
	while (*coords && ++count)
	{
		params[3] = 0;
		params[2] = 3;
		i = -1;
		while (++i < 4)
			if ((*coords)->x[i] < params[2])
				params[2] = (*coords)->x[i];
			else if ((*coords)->x[i] > params[3])
				params[3] = (*coords)->x[i];
		params[0] = (*coords)->y[0];
		params[1] = (*coords)->y[3];
		make_bias(coords, params);
	}
	*coords = init;
	return (count);
}

int			check_figures(t_coord **cs)
{
	t_coord		*save;
	int			i;
	int			j;
	int			connects;

	save = *cs;
	while (*cs)
	{
		connects = 0;
		i = -1;
		while (++i < 3)
		{
			j = i;
			while (++j < 4)
				if (((*cs)->x[i] == (*cs)->x[j] &&
	ft_abs((*cs)->y[i] - (*cs)->y[j]) == 1) || ((*cs)->y[i] == (*cs)->y[j] &&
	ft_abs((*cs)->x[i] - (*cs)->x[j]) == 1))
					connects++;
		}
		if (connects < 3)
			return (0);
		*cs = (*cs)->next;
	}
	*cs = save;
	return (1);
}
