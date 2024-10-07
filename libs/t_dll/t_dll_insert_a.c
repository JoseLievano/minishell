/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dll_insert_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:32:01 by jlievano          #+#    #+#             */
/*   Updated: 2024/06/18 16:34:52 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dll.h"

static void	insert_node_middle(t_dll *node, t_dll *new_node)
{
	t_dll	*next;

	next = node->next;
	node->next = new_node;
	new_node->prev = node;
	new_node->next = next;
	next->prev = new_node;
	t_dll_update_index(new_node);
}

void	t_dll_insert_a(t_dll **head, t_dll *new_node, size_t index)
{
	t_dll	*element;
	size_t	lst_size;

	element = t_dll_get_head(*head);
	lst_size = t_dll_size(element);
	if (lst_size == 0 || index >= lst_size)
		return ;
	if (index == 0)
	{
		(t_dll_add_front(head, new_node));
		return ;
	}
	if (index == (lst_size - 1))
	{
		t_dll_add_back(head, new_node);
		return ;
	}
	element = t_dll_get_node_index(element, index);
	insert_node_middle(element, new_node);
	return ;
}