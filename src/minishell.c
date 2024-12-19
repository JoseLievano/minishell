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
	t_minishell	*minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	minishell->cmdt = NULL;
	minishell->line = NULL;
	minishell->pipe_holder = NULL;
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
	t_minishell	*shell;

	shell = construct_minishell(envp);
	ft_parse_args(shell, argc, argv);
	if (shell->interactive_mode)
		ft_interactive_shell(shell);
	else
		ft_noninteractive_shell(shell);
	return (0);
}
