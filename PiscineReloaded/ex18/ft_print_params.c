/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:16:41 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/21 12:06:17 by sdurgan          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 0)
		return (0);
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
