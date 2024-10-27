/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:23 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/27 18:34:56 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parser(void)
{
	t_dll *token_list;

	token_list = read_through_input(ft_reader());
	if (valid_syntax(token_list))
		printf("Pipes clear");
	else
		printf("Invalid syntax");
	printf("Hello there from parser");
	print_cmd_table(get_test(3));

}

