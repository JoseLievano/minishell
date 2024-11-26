/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:07:17 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/03 02:14:36 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static bool	valid_pipes_tokens(t_dll *token_list)
{
	t_dll	*head;
	t_token	*tk;
	t_token	*ntk;

	head = t_dll_get_head(token_list);
	if (((t_token *)head->content)->type == TOKEN_PIPE)
		return (false);
	while (head)
	{
		tk = (t_token *)head->content;
		if (head->next)
		{
			ntk = (t_token *)head->next->content;
			if (tk->type == TOKEN_PIPE && ntk->type == TOKEN_PIPE)
				return (false);
		}
		head = head->next;
	}
	return (true);
}

bool	valid_syntax(t_dll *token_list)
{
	ft_cmd_btwn_redir(token_list);
	read_through_list(token_list);
	if (!valid_pipes_tokens(token_list))
		return (false);
	if (!valid_redirections(token_list))
		return (false);
	return (true);
}
