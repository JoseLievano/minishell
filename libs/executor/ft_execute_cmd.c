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
	args_node= t_dll_get_head(cmd->arguments);
	len = t_dll_size(args_node) + 2;
	args = (char **)malloc(sizeof(char *) * len);
	args[i] = ft_strdup(cmd->name);
	i++;
	while (i < len)
	{
		args_node= t_dll_get_node_index(args_node, j);
		if (!args_node)
			break ;
		args[i] = ft_strdup(((t_arg *)args_node->content)->value);
		i++;
		j++;
	}
	args[i] = NULL;
	return (args);
}

static void	close_redirections(t_minishell *minishell)
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

int	ft_execute_cmd(t_minishell *minishell)
{
	char	**args;
	char	**envs;
	char	*cmd_path;
	pid_t	pid;
	t_cmd	*cmd;

	cmd = (t_cmd *)minishell->cmdt->content;
	cmd_path = ft_find_cmd_path(cmd->name, minishell->envs);
	args = get_args_to_execute(cmd);
	envs = ft_envs_to_array(minishell->envs);
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd_path, args, envs) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		printf("\nout status: %d", WEXITSTATUS(status));
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	close_redirections(minishell);
	return (0);
}
