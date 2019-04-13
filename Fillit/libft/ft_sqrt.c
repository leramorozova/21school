/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:12:30 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/07 17:27:48 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long int	sqrt;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	sqrt = 1;
	while (sqrt * sqrt < nb)
		sqrt++;
	if (sqrt * sqrt != (long long int)nb)
		sqrt--;
	return (sqrt);
}
