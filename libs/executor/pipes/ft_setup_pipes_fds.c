/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_pipes_fds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:06:57 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/06 14:06:58 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static bool	set_pipe_in_fd(t_dll *piped_node, int fd)
{
	t_piped_cmd	*pipe_cmd;

	pipe_cmd = (t_piped_cmd *)piped_node->content;
	if (pipe_cmd->position == PIPE_UNDEFINED)
		return (false);
	if (pipe_cmd->position == PIPE_START)
		return (true);
	pipe_cmd->new_stdin = fd;
	return (true);
}

static bool	set_pipe_out_fd(t_dll *piped_node, int fd)
{
	t_piped_cmd	*pipe_cmd;

	pipe_cmd = (t_piped_cmd *)piped_node->content;
	if (pipe_cmd->position == PIPE_UNDEFINED)
		return (false);
	if (pipe_cmd->position == PIPE_END)
		return (true);
	pipe_cmd->new_stdout = fd;
	return (true);
}

bool	ft_setup_pipes_fds(t_piph *holder)
{
	int		i;
	int		pipe_fds[2];
	t_dll	*current;
	t_dll	*next;

	current = NULL;
	i = 0;
	next = NULL;
	current = t_dll_get_head(holder->pipes_cmd);
	while (i < holder->pipes_count && current)
	{
		if (pipe(pipe_fds))
			return (false);
		next = current->next;
		if (!set_pipe_out_fd(current, pipe_fds[1]))
			return (false);
		if (next && !set_pipe_in_fd(next, pipe_fds[0]))
			return (false);
		current = next;
	}
	return (true);
}
