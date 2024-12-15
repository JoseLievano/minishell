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

t_minishell	*construct_minishell(char **envp)
{
	t_minishell *minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	minishell->cmdt = NULL;
	minishell->line = NULL;
	minishell->last_output = 0;
	minishell->envs = get_env_var_list(envp);
	ft_set_shell_path(minishell);
	minishell->new_stdin = -1;
	minishell->new_stdout = -1;
	minishell->default_stdin = dup(STDIN_FILENO);
	minishell->default_stdout = dup(STDOUT_FILENO);
	minishell->interactive_mode = true;
	return (minishell);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1 && *argv[1] == '1')
	{
		char *input = ft_reader();
		rl_clear_history();
		free(input);
	}
	else if (argc > 1 && *argv[1] == '2')
	{
		char *str = ft_strdup("echo hello");
		t_dll *tokens =  NULL;
		tokens = read_through_input(str);
		//read_through_list(tokens);
		free_nodes(tokens);
		tokens = NULL;
		printf("\n----------\n");
		free(str);
		//rl_clear_history();
	}
	else if (argc > 1 && *argv[1] == '3')
	{
		char *str =  ft_strdup("echo hello there | wc -l");
		t_dll *tokens = read_through_input(str);
		t_cmdt *cmdt = ft_parser(tokens);
		free_nodes(tokens);
		free(str);
		if (cmdt)
			ft_clean_cmdt(cmdt);
	}
	else if (argc > 1 && *argv[1] == '4')
	{
		t_minishell *shell = construct_minishell(envp);
		t_dll		*token_list;
		token_list = NULL;
		shell->line = ft_reader();
		token_list = read_through_input(shell->line);
		shell->cmdt = ft_parser(token_list);
		ft_expander(shell);
		print_cmd_table(shell->cmdt);
		ft_clean_cmdt(shell->cmdt);
		free(shell->line);
		free_nodes(token_list);
	}
	else if (argc > 1 && *argv[1] == '5')
	{
		t_minishell *shell = construct_minishell(envp);
		ft_parse_args(shell, argc, argv);
		if (shell->interactive_mode)
			ft_interactive_shell(shell);
		else
			ft_noninteractive_shell(shell);
	}
	return (0);
}
