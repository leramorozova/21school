/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:12:30 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/20 19:25:20 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	upper;
	int sqrt;

	upper = 46341;
	sqrt = 0;
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (sqrt <= nb / 2 && sqrt < upper)
	{
		if (sqrt * sqrt != nb)
			sqrt++;
		else
			return (sqrt);
	}
	return (0);
}
