/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_pipes_cmds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:04:10 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/15 23:04:12 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

void	ft_setup_first_cmd(t_piped_cmd *pipe_cmd)
{
	if (pipe_cmd->new_stdout != -1)
	{
		dup2(pipe_cmd->new_stdout, STDOUT_FILENO);
		close(pipe_cmd->new_stdout);
	}
}

void	ft_setup_middle_cmd(t_piped_cmd *pipe_cmd)
{
	if (pipe_cmd->new_stdout != -1)
	{
		dup2(pipe_cmd->new_stdout, STDOUT_FILENO);
		close(pipe_cmd->new_stdout);
	}
	if (pipe_cmd->new_stdin != -1)
	{
		dup2(pipe_cmd->new_stdin, STDIN_FILENO);
		close(pipe_cmd->new_stdin);
	}
}

void	ft_setup_last_cmd(t_piped_cmd *pipe_cmd)
{
	if (pipe_cmd->new_stdin != -1)
	{
		dup2(pipe_cmd->new_stdin, STDIN_FILENO);
		close(pipe_cmd->new_stdin);
	}
}
