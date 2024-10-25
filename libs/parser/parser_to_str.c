/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:12:38 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/25 19:22:17 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	print_cmd_table(t_cmdt *cmd_table)
{
	char *type;
	if (cmd_table->type == PIPE_SEQ)
		type = "PIPE_SEQ";
	else
		type = "COMMAND";
	printf("\n\n____________\n\nParser output:\n\n");
	printf("t_cmdt:\n{\n	type : %s\n}", type);
	printf("\n\n_____________\n\n");
}