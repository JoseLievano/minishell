/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:23 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 13:39:24 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parser(void)
{
	t_dll *token_list;
	t_cmdt	*cmdt;

	token_list = read_through_input(ft_reader());
	//read_through_list(token_list);
	if (valid_syntax(token_list))
	{
		cmdt = ft_get_cmdt(token_list);
		print_cmd_table(cmdt);
	}
	else
		printf("Invalid syntax");
}

