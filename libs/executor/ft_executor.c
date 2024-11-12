/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:43:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/11 22:54:46 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

void ft_executor(void)
{
	printf("\nHello from executor\n\n");
	char *str1 = ft_strdup("A");
	char *str2 = ft_strdup("B");
	char *str3 = ft_strdup("C");
	char *str4 = ft_strdup("D");
	char *str5 = ft_strdup("E");
//	char *str6 = ft_strdup("F");
//	char *str7 = ft_strdup("G");
	t_dll *list;
	list = NULL;
	t_dll_add_back(&list, t_dll_new(str1));
	t_dll_add_back(&list, t_dll_new(str2));
	t_dll_add_back(&list, t_dll_new(str3));
	t_dll_add_back(&list, t_dll_new(str4));
	t_dll_add_back(&list, t_dll_new(str5));
//	t_dll_add_back(&list, t_dll_new(str6));
//	t_dll_add_back(&list, t_dll_new(str7));
	t_dll *head = t_dll_get_head(list);
	while (list)
	{
		printf("%d > %s\n", (int)list->index, (char *)list->content);
		list = list->next;
	}
	t_dll_move_to(&head, 3, 2);
	printf("\n\nModified list\n");
	while(head)
	{
		printf("%d > %s\n", (int)head->index, (char *)head->content);
		head = head->next;
	}
}