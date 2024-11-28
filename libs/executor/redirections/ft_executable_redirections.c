/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executable_redirections.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:50:32 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/27 13:50:32 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static bool	is_input_redir_node(t_dll *node)
{
	t_redir	*redir;

	redir = (t_redir *)node->content;
	if (redir->type == REDIR_HEREDOC || redir->type == REDIR_INPUT)
		return (true);
	return (false);
}

static bool	is_output_redir_node(t_dll *node)
{
	t_redir	*redir;

	redir = (t_redir *)node->content;
	if (redir->type == REDIR_APPEND || redir->type == REDIR_OUTPUT)
		return (true);
	return (false);
}

int	get_exec_input_redirection(t_minishell *minishell)
{
	t_dll	*redir_node;

	redir_node = ((t_cmd *)minishell->cmdt->content)->redirections;
	redir_node = t_dll_get_head(redir_node);
	while (redir_node)
	{
		if (!is_input_redir_node(redir_node))
			return (-1);
		if (redir_node->next)
		{
			if (is_output_redir_node(redir_node->next))
				return (((t_redir *)redir_node->content)->fd);
		}
		redir_node = redir_node->next;
	}
	return (-1);
}

int	get_exec_out_redirection(t_minishell *minishell)
{
	t_dll	*r_tail;

	r_tail = t_dll_get_tail(((t_cmd *)minishell->cmdt->content)->redirections);
	if (is_output_redir_node(r_tail))
		return (((t_redir *)r_tail->content)->fd);
	return (-1);
}

int	ft_process_exec_redirections(t_minishell *minishell)
{
	if (t_dll_size(((t_cmd *)minishell->cmdt->content)->redirections) == 0)
		return MOD_NONE;
	minishell->new_stdin = get_exec_input_redirection(minishell);
	minishell->new_stdout = get_exec_out_redirection(minishell);
	if (minishell->new_stdin != -1)
	{
		if (dup2(minishell->new_stdin, STDIN_FILENO) == -1)
			return (MOD_DUP_ERROR);
	}
	if (minishell->new_stdout != -1)
	{
		if (dup2(minishell->new_stdout, STDOUT_FILENO) == -1)
			return (MOD_DUP_ERROR);
	}
	if (minishell->new_stdin != -1 && minishell->new_stdout != -1)
		return (MOD_BOTH);
	if (minishell->new_stdin != -1)
		return (MOD_IN);
	if (minishell->new_stdout != -1)
		return (MOD_OUT);
	return (MOD_NONE);
}

