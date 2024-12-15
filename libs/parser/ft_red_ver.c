/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections_syntax_check.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 22:44:54 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static bool	argument_aft_redirection(t_dll *token_list)
{
	t_dll	*head;

	head = t_dll_get_head(token_list);
	while (head)
	{
		if (ft_is_redir_node(head))
		{
			if (((t_token *)head->next->content)->type != TOKEN_ARGUMENT)
				return (false);
		}
		head = head->next;
	}
	return (true);
}

static bool	valid_prev_token(t_dll *token)
{
	t_token	*prev_tk;

	prev_tk = NULL;
	if (token->prev)
		prev_tk = (t_token *)token->prev->content;
	else
		return (true);
	if (prev_tk->type == TOKEN_COMMAND
		|| prev_tk->type == TOKEN_PIPE
		|| prev_tk->type == TOKEN_ARGUMENT
		|| prev_tk->type == TOKEN_FLAG)
		return (true);
	return (false);
}

static bool	argument_bfr_redirection(t_dll *token_list)
{
	t_dll	*head;
	t_token	*tk;

	head = t_dll_get_head(token_list);
	while (head)
	{
		tk = (t_token *)head->content;
		if (tk->type == TOKEN_REDIRECTION_IN
			|| tk->type == TOKEN_REDIRECTION_APPEND
			|| tk->type == TOKEN_REDIRECTION_OUT)
		{
			if (!valid_prev_token(head))
				return (false);
		}
		head = head->next;
	}
	return (true);
}

bool	valid_redirections(t_dll *token_list)
{
	if (!argument_aft_redirection(token_list))
		return (false);
	if (!argument_bfr_redirection(token_list))
		return (false);
	return (true);
}
