/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:32:41 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/21 12:10:37 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 0)
		return (0);
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			argv[0] = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = argv[0];
			i = 1;
		}
		else
			i++;
	}
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
