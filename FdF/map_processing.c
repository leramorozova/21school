/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:59:31 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/14 11:36:00 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  В этом файле происходит чтение, проверка на валидность и запись карты
 *  в структуру */

#include "fdf.h"

// добавляю точку карты в конец структуры
t_map		*add_dot(t_map **map)
{
	t_map	*new_dot;
	t_map	*head;

	if (!(new_dot = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	head = *map;
	while (*map && (*map)->next)
		*map = (*map)->next;
	if (*map)
	{
		(*map)->next = new_dot;
		*map = head;
	}
	else
		*map = new_dot;
	new_dot->next = NULL;
	return (new_dot);
}

// удаление мапы - от утечек
void		del_map(t_map **map)
{
	t_map	*tmp;

	if (*map)
	{
		while (*map)
		{
			tmp = (*map)->next;
			free(*map);
			*map = tmp;
		}
		*map = NULL;
	}
}

// проверка карты на прямоугольность
static int		validation(t_map **map, char **line, int len, const int fd)
{
	char	**row;
	int		counter;

	counter = 0;
	row = ft_strsplit(*line, ' ');
	while (row[counter])
		counter++;
//	ft_delarr(&row);
	if (counter != len && len != 0)
	{
		perror("Map is not valid!\nProgramm has been aborted");
		ft_strdel(line);
		del_map(map);
		close(fd);
		exit(0);
	}
	else
		len = counter;
	return (len);
}

// заполняю структуру t_map информацией из карты
static void		map_constructor(t_mlx *mlx, t_map **map, char *line, int y)
{
	char	**row;
	int		counter;
	t_map	*end;

	counter = 0;
	row = ft_strsplit(line, ' ');
	while (row[counter])
	{
		end = add_dot(map);
		end->x = counter;
		end->y = y;
		end->z = ft_atoi(row[counter]);
		counter++;
	}
	mlx->width = counter;
	mlx->height += 1;
//	ft_delarr(&row);
}

// главная функция, в которой все и происходит, здесь читаю из файла
t_map			*read_map(char *filename, t_map *map, t_mlx *mlx)
{
	char		*line;
	size_t		len;
	int			fd;
	int			y;

	len = 0;
	y = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		len = validation(&map, &line, len, fd);
		map_constructor(mlx, &map, line, y);
		ft_strdel(&line);
		y += 1;
	}
	close(fd);
	return (map);
}
