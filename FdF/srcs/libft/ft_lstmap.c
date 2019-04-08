/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:05:38 by sdurgan           #+#    #+#             */
/*   Updated: 2018/12/03 13:36:39 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*save;

	if (!f)
		return (NULL);
	if (lst)
	{
		fresh = f(lst);
		save = fresh;
		while (lst->next)
		{
			lst = lst->next;
			if (!(fresh->next = f(lst)))
			{
				ft_lstfree(&save);
				save = NULL;
				return (NULL);
			}
			else
				fresh = fresh->next;
		}
		return (save);
	}
	return (NULL);
}
