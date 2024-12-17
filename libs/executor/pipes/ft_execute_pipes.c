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

static void	close_all_pipes(t_dll *pipe_head)
{
	t_dll		*head;
	t_piped_cmd	*cmd;

	head = t_dll_get_head(pipe_head);
	while (head)
	{
		cmd = (t_piped_cmd *)head->content;
		if (cmd->new_stdin != -1)
		{
			close(cmd->new_stdin);
			cmd->new_stdin = -1;
		}
		if (cmd->new_stdout != -1)
		{
			close(cmd->new_stdout);
			cmd->new_stdout = -1;
		}
		head = head->next;
	}
}

static void	close_unused_pipes(t_dll *pipe_head, t_piped_cmd *current_cmd)
{
	t_dll		*head;
	t_piped_cmd	*cmd;

	head = t_dll_get_head(pipe_head);
	while (head)
	{
		cmd = (t_piped_cmd *)head->content;
		if (cmd != current_cmd)
		{
			if (cmd->new_stdin != -1)
				close(cmd->new_stdin);
			if (cmd->new_stdout != -1)
				close(cmd->new_stdout);
		}
		head = head->next;
	}
}

static void	exec_pipe(t_piped_cmd *pipe_cmd, char **envs, t_dll *pipe_head)
{
	pipe_cmd->pid = fork();
	if (pipe_cmd->pid == 0)
	{
		ft_setup_child_signals();
		ft_pid_pipe_fds(pipe_cmd);
		close_unused_pipes(pipe_head, pipe_cmd);
		if (execve(pipe_cmd->args[0], pipe_cmd->args, envs) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pipe_cmd->pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	ft_close_pipe_cmd_fds(pipe_cmd);
}

static bool	execute_pipeline(t_dll *pipe_head, char **envs)
{
	t_dll		*head;
	int			status;
	t_piped_cmd	*current;

	head = t_dll_get_head(pipe_head);
	if (!head)
		return (false);
	while (head)
	{
		exec_pipe((t_piped_cmd *)head->content, envs, pipe_head);
		head = head->next;
	}
	ft_setup_parent_signals();
	head = t_dll_get_head(pipe_head);
	while (head)
	{
		current = (t_piped_cmd *)head->content;
		waitpid(current->pid, &status, 0);
		if (WIFSIGNALED(status))
			g_signal_received = WTERMSIG(status);
		head = head->next;
	}
	close_all_pipes(pipe_head);
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
	if (minishell->interactive_mode)
		ft_setup_interactive_signals();
	return (0);
}
