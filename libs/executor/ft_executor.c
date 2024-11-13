/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:43:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/13 12:11:18 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

void ft_executor(void)
{
	t_cmdt *cmdt = ft_parser(read_through_input(ft_reader()));
	print_cmd_table(cmdt);
	ft_clean_cmdt(cmdt);
}