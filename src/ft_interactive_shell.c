/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive_shell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:47:15 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/04 11:47:16 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_interactive_shell(t_minishell *minishell)
{
	t_dll	*token_list;

	token_list = NULL;
	while (1)
	{
		minishell->interactive_mode = true;
		minishell->line = ft_reader();
		minishell->interactive_mode = false;
		token_list = read_through_input(minishell->line);
		minishell->cmdt = ft_parser(token_list);
		if (minishell->cmdt)
		{
			ft_executor(minishell);
			ft_clean_cmdt(minishell->cmdt);
		}
		free(minishell->line);
		free_nodes(token_list);
	}
}
