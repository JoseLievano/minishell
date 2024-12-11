/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:46:48 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/09 14:46:49 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

void	close_pipes(t_piped_cmd *current)
{
	if (current->new_stdin != -1)
		close(current->new_stdin);
	if (current->new_stdout != -1)
		close(current->new_stdout);
}

static void	wait_for_pipes(t_dll *pipe_head)
{
	t_dll		*head;
	t_piped_cmd	*current;

	head = t_dll_get_head(pipe_head);
	current = NULL;
	while (head)
	{
		current = (t_piped_cmd *)head->content;
		waitpid(current->pid, NULL, 0);
		head = head->next;
	}
}

static void	exec_pipe(t_piped_cmd *pipe_cmd, char **envs)
{
	pipe_cmd->pid = fork();

	if (pipe_cmd->pid == 0)
	{

		if (pipe_cmd->new_stdin != -1)
		{
			dup2(pipe_cmd->new_stdin, STDIN_FILENO);
			close(pipe_cmd->new_stdin);
		}
		if (pipe_cmd->new_stdout != -1)
		{
			dup2(pipe_cmd->new_stdout, STDOUT_FILENO);
			close(pipe_cmd->new_stdout);
		}
		if (execve(pipe_cmd->args[0], pipe_cmd->args, envs) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	close_pipes(pipe_cmd);
}

static bool execute_pipeline(t_dll *pipe_head, char **envs)
{
	t_dll	*head;

	head = t_dll_get_head(pipe_head);
	if (!head)
		return (false);
	while (head)
	{
		exec_pipe((t_piped_cmd *)head->content, envs);
		head = head->next;
	}
	wait_for_pipes(pipe_head);
	return (true);
}

int	ft_execute_pipes(t_minishell *minishell)
{
	t_dll	*piped_cmd_list;
	char	**envs;

	ft_pipe_holder_constructor(minishell);
	if (!minishell->pipe_holder)
		return (1);
	ft_setup_pipes_fds(minishell->pipe_holder);
	piped_cmd_list = t_dll_get_head(minishell->pipe_holder->pipes_cmd);
	envs = ft_envs_to_array(minishell->envs);
	if (!execute_pipeline(piped_cmd_list, envs))
	{
		ft_free_char_array(envs);
		return (1);
	}
	ft_free_char_array(envs);
	return (0);
}
