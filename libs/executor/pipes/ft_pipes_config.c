/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:05:04 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/06 04:05:05 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static t_piped_cmd	*init_pipe(char *cmd)
{
	t_piped_cmd	*to_return_pipe;

	to_return_pipe = (t_piped_cmd *)malloc(sizeof(t_piped_cmd));
	to_return_pipe->args = NULL;
	to_return_pipe->pid = -1;
	to_return_pipe->position = PIPE_UNDEFINED;
	to_return_pipe->cmd = ft_strdup(cmd);
	to_return_pipe->def_stdin =  -1;
	to_return_pipe->def_stdout =  -1;
	to_return_pipe->new_stdin = -1;
	to_return_pipe->new_stdout = -1;
	to_return_pipe->execve_result = 0;
	return (to_return_pipe);
}

static void	set_pipes_list(t_piph *holder, t_pipes *pipes_cmd)
{
	t_dll	*list;
	t_dll	*cmd_list;
	char	*current_cmd;

	list = NULL;
	current_cmd = NULL;
	cmd_list = t_dll_get_head(pipes_cmd->cmds);
	while (cmd_list)
	{
		current_cmd = (char *)cmd_list->content;
		t_dll_add_back(&list, t_dll_new(init_pipe(current_cmd)));
		cmd_list = cmd_list->next;
	}
	holder->pipes_cmd = list;
}

static char	**get_current_args(char *shell_path, char *cmd)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * 5);
	args[0] = ft_strdup(shell_path);
	args[1] = ft_strdup("5");
	args[2] = ft_strdup("-c");
	args[3] = ft_strdup(cmd);
	args[4] = NULL;
	return (args);
}

static void	setup_args(t_dll *list, char *shell_path)
{
	t_dll		*head;
	t_piped_cmd	*current_piped_cmd;
	char		*cmd;

	head = t_dll_get_head(list);
	current_piped_cmd = NULL;
	cmd = NULL;
	while (head)
	{
		current_piped_cmd = (t_piped_cmd *)head->content;
		cmd = current_piped_cmd->cmd;
		current_piped_cmd->args = get_current_args(shell_path, cmd);
		head = head->next;
	}
}

bool	ft_pipe_holder_constructor(t_minishell *minishell)
{
	t_piph		*pipe_holder;
	t_pipes		*pipes_cmd;

	pipe_holder = (t_piph *)malloc(sizeof(t_piph));
	if (!pipe_holder)
		return (false);
	if (minishell->cmdt->type == PIPE_SEQ)
		pipes_cmd = (t_pipes *) minishell->cmdt->content;
	else
		return (false);
	pipe_holder->pipes_count = pipes_cmd->cmd_count - 1;
	pipe_holder->pipes_cmd = NULL;
	set_pipes_list(pipe_holder, pipes_cmd);
	setup_args(pipe_holder->pipes_cmd, minishell->shell_path);
	ft_setup_piped_cmd_position(pipe_holder->pipes_cmd);
	minishell->pipe_holder = pipe_holder;
	return (true);
}
