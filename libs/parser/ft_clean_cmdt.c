/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_cmdt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:19:00 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/08 19:38:17 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	clean_redirections(t_dll *redir)
{
	t_redir	*redirection;

	redirection = (t_redir *)redir->content;
	if (redirection->delimiter)
		free(redirection->delimiter);
	if (redirection->file_path)
		free(redirection->file_path);
	free(redirection);
}

static void	clean_args(t_dll *arg_node)
{
	t_arg	*arg;

	arg = (t_arg *)arg_node->content;
	if (arg->value)
		free(arg->value);
	free(arg);
}
/*
static void	clean_commands(t_dll *command)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)command->content;
	t_dll_clear(cmd->arguments, &clean_args);
	t_dll_clear(cmd->redirections, &clean_redirections);
	free(cmd->name);
	free(cmd);
}
*/
static void clean_pipes(t_dll *pipe_cmd)
{
	if (pipe_cmd->content)
		free(pipe_cmd->content);
}

void	ft_clean_cmdt(t_cmdt *cmdt)
{
	t_cmd	*command;
	t_pipes	*pipes;

	if (cmdt->type == PIPE_SEQ)
	{
		pipes = (t_pipes *)cmdt->content;
		t_dll_clear(pipes->cmds, &clean_pipes);
		free(pipes);
	}
	else if (cmdt->type == COMMAND)
	{
		command = (t_cmd *)cmdt->content;
		t_dll_clear(command->arguments, &clean_args);
		t_dll_clear(command->redirections, &clean_redirections);
		free(command->name);
		free(command);
	}
	free(cmdt);
}
