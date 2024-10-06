/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:43 by jlievano          #+#    #+#             */
/*   Updated: 2024/09/25 16:52:44 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv)
{
	t_dll *new_node = t_dll_new(ft_strdup("hola\n"));
	printf("list size: %d\n", (int)t_dll_size(new_node));
	printf("Args counter: %d\n", argc);
	printf("ARG 2: %s", argv[1]);
	ft_reader_test();
	return (0);
}
