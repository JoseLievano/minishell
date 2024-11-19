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

static t_minishell	*construct_minishell(char **envp)
{
	t_minishell *minishell;

	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	minishell->cmdt = NULL;
	minishell->line = NULL;
	minishell->last_output = 0;
	minishell->envs = get_env_var_list(envp);
	return (minishell);
}

int	main(int argc, char **argv, char **envp)
{
	/*
	t_minishell *minishell = construct_minishell(envp);
	printf("%d\n", (int)t_dll_size(minishell->envs));
	t_dll *envs = t_dll_get_head(minishell->envs);
	while(envs)
	{
		t_env *ac = (t_env *)envs->content;
		printf("\n-----\n%s\n%s\n-------", ac->key, ac->value);
		envs = envs->next;
	}

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
		char *str =  ft_reader();
		t_dll *tokens = read_through_input(str);
		t_cmdt *cmdt = ft_parser(tokens);
		print_cmd_table(cmdt);
		free_nodes(tokens);
		free(str);
		//rl_clear_history();
		ft_clean_cmdt(cmdt);
	}
	else if (argc > 1 && *argv[1] == '4')
	{
		t_minishell *minishell = construct_minishell(envp);
		minishell->line = ft_strdup("echo \"Hello $USER\"");
		minishell->cmdt = ft_parser(read_through_input(minishell->line));
		ft_expander(minishell);
	}
	else if (argc > 1 && *argv[1] == '5')
	{
		t_minishell *shell = construct_minishell(envp);
		t_dll		*token_list;

		token_list = NULL;
		while (1)
		{
			shell->line = ft_reader();
			token_list = read_through_input(shell->line);
			shell->cmdt = ft_parser(token_list);
			ft_executor(shell);
			ft_clean_cmdt(shell->cmdt);
			free(shell->line);
			free_nodes(token_list);
		}
	}
	return (0);
}
