/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:14:20 by sdurgan           #+#    #+#             */
/*   Updated: 2018/11/30 12:15:48 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strtrim(char const *s);

int	main(void)
{
	ft_putnbr(sizeof("\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t"));
	printf("%s\n", ft_strtrim("\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  "));
	//printf("%s\n", ft_strtrim(" 	oo 	"));
	//printf("%s\n", ft_strtrim("   "));
	//printf("%s\n", ft_strtrim("o  o"));
	return (0);
}
