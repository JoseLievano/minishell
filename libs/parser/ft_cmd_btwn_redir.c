/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_btwn_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:52:13 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/26 17:52:14 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	check_next_arg_node(t_dll *redir_node)
{
	t_dll	*nxt;
	t_dll	*aft_nxt;

	nxt = NULL;
	aft_nxt = NULL;
	nxt = redir_node->next;
	if (!nxt)
		return ;
	aft_nxt = nxt->next;
	if (!aft_nxt)
		return ;
	if (((t_token *)nxt->content)->type == TOKEN_ARGUMENT)
	{
		if (((t_token *)aft_nxt->content)->type == TOKEN_ARGUMENT)
			((t_token *)aft_nxt->content)->type = TOKEN_COMMAND;
	}
}

void	ft_cmd_btwn_redir(t_dll *token_list)
{
	t_dll	*head;
	t_token	*temp_tk;

	head = t_dll_get_head(token_list);
	temp_tk = NULL;
	while (head)
	{
		temp_tk = (t_token *)head->content;
		if (temp_tk->type == TOKEN_REDIRECTION_IN
			|| temp_tk->type == TOKEN_REDIRECTION_OUT
			|| temp_tk->type == TOKEN_REDIRECTION_APPEND
			|| temp_tk->type == TOKEN_HEREDOC)
		{
			check_next_arg_node(head);
		}
		head = head->next;
	}
}
