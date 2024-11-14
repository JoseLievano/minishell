/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:07:15 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/08 19:49:14 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_minishell	*construct_minishell(void)
{
	t_minishell *minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	minishell->cmdt = NULL;
	minishell->envs = NULL;
	minishell->line = NULL;
	minishell->last_output = 0;
	return (minishell);
}

int	main(int argc, char **argv)
{
	/*
	t_minishell *minishell = construct_minishell();

	while(1)
	{
		minishell->line = ft_reader();
		minishell->cmdt = ft_parser(read_through_input(minishell->line));
		ft_clean_cmdt(minishell->cmdt);
		free(minishell->line);
	}
	*/
	if (argc > 1 && *argv[1] == '1')
	{
		char *input = ft_reader();
		rl_clear_history();
		free(input);
	}
	else if (argc > 1 && *argv[1] == '2')
	{
		char *str = ft_strdup("echo hi");
		t_dll *tokens = read_through_input(str);
		free(str);
		//rl_clear_history();
		free_nodes(tokens);
	}
	else if (argc > 1 && *argv[1] == '3')
	{
		char *str = ft_strdup("echo hello there | wc -l");
		t_dll *tokens = read_through_input(str);
		t_cmdt *cmdt = ft_parser(tokens);
		free_nodes(tokens);
		free(str);
		//rl_clear_history();
		ft_clean_cmdt(cmdt);
	}
	else if (argc > 1 && *argv[1] == '4')
	{
		t_minishell *minishell = construct_minishell();
		minishell->line = ft_strdup("echo \"Hello $USER\"");
		minishell->cmdt = ft_parser(read_through_input(minishell->line));
		ft_expander(minishell);
	}
	else if (argc > 1 && *argv[1] == '5')
		ft_executor();
	return (0);
}
