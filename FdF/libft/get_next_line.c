/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 02:11:57 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/02 12:46:12 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_idx(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (str[i] == '\0') ? (-1) : (i);
}

int		static_processing(char **save, char **line, int fd)
{
	char	*temp;

	if (ft_strchr(save[fd], '\n'))
	{
		*line = ft_strsub(save[fd], 0, ft_strchr_idx(save[fd]));
		temp = ft_strdup(ft_strchr(save[fd], '\n') + 1);
		ft_strdel(&save[fd]);
		save[fd] = temp;
		if (ft_strlen(save[fd]) == 0)
			ft_strdel(&save[fd]);
	}
	else
	{
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			rd;
	char		buf[BUFF_SIZE + 1];
	char		*checkpoint;
	static char	*save[4864];

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		if (!save[fd])
			save[fd] = ft_strnew(1);
		checkpoint = ft_strjoin(save[fd], buf);
		ft_strdel(&save[fd]);
		save[fd] = checkpoint;
		if (ft_strchr(save[fd], '\n'))
			return (static_processing(save, line, fd));
	}
	if (!rd && (!save[fd] || ft_strlen(save[fd]) == 0))
		return (0);
	return (static_processing(save, line, fd));
}
