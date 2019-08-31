/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:51:10 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/03 13:37:47 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfreeone(t_list **alst)
{
	if (alst)
	{
		free((*alst)->content);
		free((void *)((*alst)->content_size));
		free(*alst);
	}
	*alst = NULL;
}
