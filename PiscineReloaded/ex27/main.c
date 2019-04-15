/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:30:06 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/20 19:30:45 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int		main(int argc, char **argv)
{
	int		f;
	char	buf[1];

	f = 0;
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc == 1)
		ft_putstr("File name missing.\n");
	else
	{
		f = open(argv[1], O_RDONLY);
		if (f < 0)
			return (-1);
		else
		{
			while (read(f, buf, 1))
				write(1, &buf, 1);
		}
	}
	f = close(f);
	if (f < 0)
		return (-1);
	else
		return (0);
}
