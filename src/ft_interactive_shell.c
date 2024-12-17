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
	ft_setup_interactive_signals();
	while (1)
	{
		minishell->interactive_mode = true;
		minishell->line = ft_reader();
		minishell->interactive_mode = false;
		token_list = read_through_input(minishell->line);
		minishell->cmdt = ft_parser(token_list);
		ft_expander(minishell);
		if (minishell->cmdt)
		{
			ft_executor(minishell);
			if (g_signal_received == SIGINT)
			{
				minishell->last_output = 130;
				g_signal_received = 0;
			}
		}
		free_nodes(token_list);
		ft_partial_clean_minishell(minishell);
	}
}
