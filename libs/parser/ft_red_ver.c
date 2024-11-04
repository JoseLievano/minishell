/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections_syntax_check.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/04 13:37:00 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static bool	valid_heredoc(t_dll *token_list)
{
	t_dll	*head;
	t_token	*token;

	head = t_dll_get_head(token_list);
	while (head)
	{
		token = (t_token *)head->content;
		if (token->type == TOKEN_HEREDOC)
		{
			if (head->prev)
				if (((t_token *)head->prev->content)->type != TOKEN_COMMAND &&
					((t_token *)head->prev->content)->type != TOKEN_PIPE)
					return (false);
			if (head->next)
			{
				if (((t_token *)head->next->content)->type != TOKEN_ARGUMENT)
					return (false);
			}
			else
				return (false);
		}
		head = head->next;
	}
	return (true);
}

static bool	argument_aft_redirection(t_dll *token_list)
{
 	t_dll	*head;
	t_token	*tk;
	t_token	*ntk;

	head = t_dll_get_head(token_list);
	while (head)
	{
		tk = (t_token *)head->content;
		if (head->next)
		{
			ntk = (t_token *)head->next->content;
			if ((tk->type == TOKEN_REDIRECTION_IN ||
				tk->type == TOKEN_REDIRECTION_OUT ||
				tk->type == TOKEN_REDIRECTION_APPEND ||
				tk->type == TOKEN_HEREDOC) &&
				ntk->type != TOKEN_ARGUMENT)
				return (false);
		}
		head = head->next;
	}
	return (true);
}

static bool	valid_prev_token(t_dll *token)
{
	t_token	*prev_tk;
	t_token	*crr_tk;

	if (token->prev)
		prev_tk = (t_token *)token->prev->content;
	else
		return (false);
	crr_tk = (t_token *)token->content;
	if (crr_tk->type == TOKEN_HEREDOC && prev_tk->type == TOKEN_HEREDOC)
		return (true);
	return (true);
}

static bool argument_bfr_redirection(t_dll *token_list)
{
	t_dll	*head;
	t_token	*tk;

	head = t_dll_get_head(token_list);
	while (head)
	{
		tk = (t_token *)head->content;
		if (tk->type == TOKEN_REDIRECTION_IN ||
			tk->type == TOKEN_REDIRECTION_APPEND ||
			tk->type == TOKEN_REDIRECTION_OUT)
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
	return (argument_aft_redirection(token_list) &&
          valid_heredoc(token_list) && argument_bfr_redirection(token_list));
}
