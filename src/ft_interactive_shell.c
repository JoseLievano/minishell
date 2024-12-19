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

bool	ft_check_eof(char *input)
{
	if (!input)
		return (true);
	return (false);
}

static void	exit_interactive_shell(t_minishell *minishell)
{
	int	exit_status;

	exit_status = minishell->last_output;
	printf("exit\n");
	rl_clear_history();
	ft_clean_minishell(minishell);
	exit(exit_status);
}

static void	process(t_minishell *minishell, char *input, t_dll *token_list)
{
	minishell->line = input;
	minishell->cmdt = ft_parser(token_list);
	if (minishell->cmdt)
	{
		ft_expander(minishell);
		ft_executor(minishell);
	}
	ft_partial_clean_minishell(minishell);
	free_nodes(token_list);
}

void	ft_interactive_shell(t_minishell *minishell)
{
	char	*input;
	t_dll	*token_list;

	ft_setup_interactive_signals();
	token_list = NULL;
	while (1)
	{
		input = ft_reader();
		if (!input)
			break ;
		else
			token_list = read_through_input(input);
		if (token_list)
		{
			process(minishell, input, token_list);
		}
		else
			free(input);
	}
	exit_interactive_shell(minishell);
}
