/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:07:17 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/03 01:08:24 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static bool	valid_pipes_tokens(t_dll *token_list)
{
	t_dll	*head;
	t_token	*ac_token;
	t_token *next_token;

	head = t_dll_get_head(token_list);
	if (((t_token *)head->content)->type == TOKEN_PIPE)
		return (false);
	while (head)
	{
		ac_token = (t_token *)head->content;
		next_token = (t_token *)head->next->content;
		if (head->next)
		{
			if (ac_token->type == TOKEN_PIPE && next_token->type == TOKEN_PIPE)
				return (false);
		}
		head = head->next;
	}
	return (true);
}

bool	valid_syntax(t_dll *token_list)
{
	if (!valid_pipes_tokens(token_list))
	{
		printf("Invalid syntax error token |");
		return (false);
	}
	return (true);
}
