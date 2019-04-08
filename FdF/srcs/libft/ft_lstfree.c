/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltsfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:55:19 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/03 13:37:11 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **alst)
{
	if (!alst)
		return ;
	if ((*alst)->next)
		ft_lstfree(&((*alst)->next));
	ft_lstfreeone(alst);
	alst = NULL;
}
