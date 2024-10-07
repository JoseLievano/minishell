/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:17:09 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/07 14:50:16 by glicciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"

t_test *get_test_struct(char *str)
{
	t_test *test;

	test = (t_test *)malloc(sizeof(t_test));
	test->token_type = str;
	test->value = 1;
}

void test_clear(t_dll *node)
{
	free(node);
}

void	ft_reader_test(void)
{
	printf("\nHello there ft_reader\n");

	char *str1 = ft_strdup("demo 1");
	char *str2 = ft_strdup("demo 2");
	char *str3 = ft_strdup("demo 3");
	char *str4 = ft_strdup("demo 4");

	t_dll *list;

	list = NULL;
	list = t_dll_new(get_test_struct(str1));
	t_dll_add_back(&list, get_test_struct(str2));
	t_dll_add_front(&list, get_test_struct(str3));
	t_dll_add_back(&list, get_test_struct(str4));
	list = t_dll_get_head(list);
	t_dll_clear(list, &test_clear);
}