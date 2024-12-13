/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:07 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/19 14:33:08 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static char	**get_args_to_execute(t_cmd *cmd)
{
	char	**args;
	size_t	len;
	size_t	i;
	size_t	j;
	t_dll	*args_node;

	i = 0;
	j = 0;
	args_node = t_dll_get_head(cmd->arguments);
	len = t_dll_size(args_node) + 2;
	args = (char **)malloc(sizeof(char *) * len);
	args[i] = ft_strdup(cmd->name);
	i++;
	while (i < len)
	{
		args_node = t_dll_get_node_index(args_node, j);
		if (!args_node)
			break ;
		args[i] = ft_strdup(((t_arg *)args_node->content)->value);
		i++;
		j++;
	}
	args[i] = NULL;
	return (args);
}

void	close_redirections(t_minishell *minishell)
{
	t_dll	*redir;

	redir = ((t_cmd *)minishell->cmdt->content)->redirections;
	if (t_dll_size(redir) == 0)
		return ;
	if (minishell->new_stdin != -1)
	{
		dup2(minishell->default_stdin, STDIN_FILENO);
		minishell->default_stdin = -1;
	}
	if (minishell->new_stdout != -1)
	{
		dup2(minishell->default_stdout, STDOUT_FILENO);
		minishell->default_stdout = -1;
	}
	while (redir)
	{
		close(((t_redir *)redir->content)->fd);
		redir = redir->next;
	}
}

static bool	check_valid_args(char **args, char **envs, char *cmd_path)
{
	if (args && envs && cmd_path)
		return (true);
	ft_free_child_arrays(args, envs, cmd_path);
	return (false);
}
/*
static int	execute_child_process(t_minishell *minishell)
{


	if (ft_is_built_in(cmd->name, args, minishell))
		return (0);
	check_valid_args(args, envs, cmd_path);
	if (ft_process_exec_redirections(minishell) == MOD_DUP_ERROR)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	write(1, "BEFORE", 6);
	result = execve(cmd_path, args, envs);
	write(1, "AFTER", 5);
	if (result == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	ft_free_child_arrays(args, envs, cmd_path);
	return (result);
}
*/
int	ft_execute_cmd(t_minishell *minishell)
{
	char	**args;
	char	**envs;
	char	*cmd_path;
	t_cmd	*cmd;
	int		result;

	cmd = (t_cmd *)minishell->cmdt->content;
	cmd_path = ft_find_cmd_path(cmd->name, minishell->envs);
	args = get_args_to_execute(cmd);
	envs = ft_envs_to_array(minishell->envs);
	if (!cmd_path)
	{
		printf("%s : Command not found\n", cmd->name);
		ft_free_child_arrays(args, envs, cmd_path);
		return (127);
	}
	if (!check_valid_args(args, envs, cmd_path))
		return (500);
	if (ft_is_built_in(cmd->name, args, minishell))
		return (0);
	result = pid_execution(minishell, args, envs, cmd_path);
	ft_free_child_arrays(args, envs, cmd_path);
	return (result);
}
