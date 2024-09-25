/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:30:33 by jlievano          #+#    #+#             */
/*   Updated: 2024/04/09 04:54:36 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_content = (*f)(lst->content);
	temp = ft_lstnew(new_content);
	if (!temp)
		return (NULL);
	new_list = temp;
	lst = lst->next;
	while (lst)
	{
		new_content = (*f)(lst->content);
		temp = ft_lstnew(new_content);
		if (!temp)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
