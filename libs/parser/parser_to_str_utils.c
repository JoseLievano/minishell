/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_to_str_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:33:19 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/19 23:33:20 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	print_pipe_seq(t_pipes *pipes)
{
	t_dll	*head;

	printf("\n\t\t\t{\n\t\t\t\tcmd_count: %d,", pipes->cmd_count);
	printf("\n\t\t\t\tcmds:\n\t\t\t\t[");
	head = t_dll_get_head(pipes->cmds);
	while (head)
	{
		printf("\n\t\t\t\t\t{%s},", (char *)head->content);
		head = head->next;
	}
	printf("\n\t\t\t\t]");
}
