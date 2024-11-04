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
  	if (token_list->next)
          return (true);
	return (false);
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

bool	valid_redirections(t_dll *token_list)
{
	return (argument_aft_redirection(token_list) &&
          valid_heredoc(token_list));
}
