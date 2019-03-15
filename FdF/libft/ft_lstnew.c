/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:52:07 by sdurgan           #+#    #+#             */
/*   Updated: 2019/03/15 14:46:51 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)malloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	fresh->next = NULL;
	if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = (void *)malloc(sizeof(void) * content_size);
		if (!fresh->content)
			return (NULL);
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
	}
	return (fresh);
}
