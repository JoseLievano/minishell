/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:05:01 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 19:27:16 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_redir	*construct_empty_redirection(void)
{
	t_redir	*new_redirection;

	new_redirection = (t_redir *)malloc(sizeof(t_redir));
	new_redirection->delimiter = NULL;
	new_redirection->file_path = NULL;
	new_redirection->fd = -1;
	new_redirection->type = -1;
	return (new_redirection);
}

static t_redir	*get_single_red(t_dll *node)
{
	t_redir	*redirection;

	redirection = construct_empty_redirection();
	if (((t_token *)node->content)->type == TOKEN_HEREDOC)
	{
		redirection->delimiter = ft_strdup(((t_token *)node->next->content)->value);
		redirection->type = REDIR_HEREDOC;
	}
	else
	{
		redirection->file_path = ft_strdup(((t_token *)node->next->content)->value);
		if (((t_token *)node->content)->type == TOKEN_REDIRECTION_IN)
			redirection->type = REDIR_INPUT;
		else if (((t_token *)node->content)->type == TOKEN_REDIRECTION_OUT)
			redirection->type = REDIR_OUTPUT;
		else if (((t_token *)node->content)->type == TOKEN_REDIRECTION_APPEND)
			redirection->type = REDIR_APPEND;
	}
	return (redirection);
}

t_dll	*get_redirections(t_dll *token_list)
{
	t_dll	*head;
	t_dll	*redirections;

	redirections = NULL;
	head = t_dll_get_head(token_list);
	while (head)
	{
		if (node_is_redirection(head))
		{
			t_dll_add_back(&redirections, t_dll_new(get_single_red(head)));
			head = head->next;
		}
		head = head->next;
	}
	return (redirections);
}