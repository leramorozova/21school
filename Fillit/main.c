/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:11:51 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/08 19:14:07 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	char	*l;
	t_coord	*cs;
	int		fd;
	int		figures;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit filename\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	cs = NULL;
	if (!(l = NULL) && check_map(fd, l, &cs) != -1 && check_figures(&cs))
	{
		if (!(figures = count_bias(&cs)))
			ft_putstr("error\n");
		else if (!(try_map(figures, &cs)))
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	ft_delcoords(&cs);
	if (fd != -1)
		close(fd);
	return (0);
}
