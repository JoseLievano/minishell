/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:23 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/03 17:33:46 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parser(void)
{
	t_dll *token_list;

	token_list = read_through_input(ft_reader());
	read_through_list(token_list);
	if (valid_syntax(token_list))
		printf("Pipes clear");
	else
		printf("Invalid syntax");
	//print_cmd_table(get_test(3));
}

