/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:07:17 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/27 19:57:20 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static bool	is_token_pipe(t_dll *token)
{
	char	*token_pipe;
	int		len;

	token_pipe = "TOKEN_PIPE";
	len = (int) ft_strlen(token_pipe);
	if (!ft_strncmp(((t_token *)token->content)->type, token_pipe, len))
		return (true);
	return (false);
}

static bool	valid_pipes_tokens(t_dll *token_list)
{
	t_dll	*head;

	head = t_dll_get_head(token_list);
	if (is_token_pipe(head))
		return (false);
	while (head)
	{
		if (head->next)
		{
			if (is_token_pipe(head) && is_token_pipe(head->next))
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
