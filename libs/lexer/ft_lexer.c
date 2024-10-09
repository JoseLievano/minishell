/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/09 22:56:41 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void lexer_test(void)
{
	printf("\n=================\n");
	printf("Lexer function\n");

	t_dll *lexer_list = t_dll_new(ft_strdup("hello"));
	t_dll_add_front(&lexer_list, t_dll_new(ft_strdup("Another hello")));
	printf("Lexer list size %d\n", (int)t_dll_size(lexer_list));
	ft_reader_test();
}

