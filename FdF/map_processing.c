/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:02:09 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/06 15:02:21 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pixel.h"
//#include "mapping.h"
#include "fdf.h"
//#include <fcntl.h>
//#include <stdio.h>

static char		**map_to_arr(char *filename)
{
	char	*line;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = ft_strnew(0);
	while((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			perror("ERROR map is nor valid");
			exit(0);
		}
		buf[ret] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (ft_strsplit(line, '\n'));
}

static t_pixel	*add_dot(t_pixel **map)
{
	t_pixel	*new_dot;
	t_pixel	*head;

	if (!(new_dot = (t_pixel *)malloc(sizeof(t_pixel))))
		return (NULL);
	head = *map;
	while (*map && (*map)->right)
		*map = (*map)->right;
	if (*map)
	{
		(*map)->right = new_dot;
		*map = head;
	}
	else
		*map = new_dot;
	new_dot->right = NULL;
	return (new_dot);
}

static void		map_constructor(t_pixel **map, char *line,
		char *line_next, int y)
{
	char	**row;
	char	**row_next;
	int		counter;
	t_pixel	*end;

	counter = 0;
	row = ft_strsplit(line, ' ');
	row_next = line_next ? ft_strsplit(line_next, ' ') : NULL;
	while (row[counter])
	{
		end = add_dot(map);
		end->x = counter;
		end->y = y;
		define_colour(end, row[counter]);
		if (line_next)
		{
			end->down = (t_pixel *)malloc(sizeof(t_pixel));
			end->down->x = counter;
			end->down->y = y + 1.0;
			define_colour(end->down, row_next[counter]);
		}
		else
			end->down = NULL;
		counter++;
	}
}

t_pixel			*read_map(char *name, t_pixel *pixel, int *width, int *height)
{
	char 	**lines;
	int 	rows;
	int 	colls;
	int 	cur_colls;

	cur_colls = 0;
	colls = 0;
	rows = -1;
	lines = map_to_arr(name);
	while (lines[++rows])
	{
		cur_colls = ft_wordscnt(lines[rows], ' ');
		colls = colls == 0 ? cur_colls : colls;
		if (colls != cur_colls || (lines[rows + 1] &&
				ft_wordscnt(lines[rows + 1], ' ') != cur_colls))
			exit(0);
		lines[rows + 1] ? map_constructor(&pixel, lines[rows],
				lines[rows + 1], rows)
			: map_constructor(&pixel, lines[rows], NULL, rows);
	}
	*width = colls;
	*height = rows;
	return (pixel);
}
