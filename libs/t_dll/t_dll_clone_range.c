/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_clone_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:17:43 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/05 15:31:21 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

t_dll	*t_dll_clone_range(t_dll *n, size_t s, size_t e, t_dll *(*c)(t_dll *n))
{
	t_dll	*head;
	size_t	list_size;
	t_dll	*new_list;
	t_dll	*cloned_node;

	head = t_dll_get_head(n);
	list_size = t_dll_size(n);
	if (s > e || e >= list_size || s >= list_size)
		return (NULL);
	new_list = NULL;
	cloned_node = NULL;
	while (s <= e)
	{
		cloned_node = c(t_dll_get_node_index(head, s));
		if (!cloned_node)
			break;
		t_dll_add_back(&new_list, cloned_node);
		s++;
	}
	return (new_list);
}
