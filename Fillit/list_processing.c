/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurgan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:06:58 by sdurgan           #+#    #+#             */
/*   Updated: 2019/01/08 19:13:28 by sdurgan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		*ft_lstadd_to_end(t_coord **coordinates)
{
	t_coord *new_node;
	t_coord	*head;

	if (!(new_node = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	head = *coordinates;
	while (*coordinates && (*coordinates)->next)
		*coordinates = (*coordinates)->next;
	if (*coordinates)
	{
		(*coordinates)->next = new_node;
		*coordinates = head;
	}
	else
		*coordinates = new_node;
	new_node->next = NULL;
	return (new_node);
}

void		ft_delcoords(t_coord **coords)
{
	t_coord	*tmp;

	if (coords && *coords)
	{
		while (*coords)
		{
			tmp = (*coords)->next;
			free(*coords);
			*coords = tmp;
		}
		*coords = NULL;
	}
}
