/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <sdurgan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:26:49 by sdurgan           #+#    #+#             */
/*   Updated: 2019/04/20 08:58:05 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double nb, int power)
{
	if (power == 1)
		return (nb);
	else if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (nb * ft_power(nb, power - 1));
}
