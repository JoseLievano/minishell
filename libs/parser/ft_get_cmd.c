/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:10 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 12:33:01 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_arg	*create_arg(t_token *token)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (token->type == TOKEN_ARGUMENT)
		arg->type = ARGUMENT;
	else if (token->type == TOKEN_FLAG)
		arg->type = FLAG;
	arg->value = ft_strdup(token->value);
	return (arg);
}

static bool	token_is_redirection(t_token *token)
{
	if (token->type == TOKEN_REDIRECTION_IN ||
		token->type == TOKEN_REDIRECTION_OUT ||
		token->type == TOKEN_REDIRECTION_APPEND ||
		token->type == TOKEN_HEREDOC)
		return (true);
	return (false);
}

static t_dll	*get_arguments(t_dll *token_list)
{
	t_dll	*head;
	t_dll	*args;
	t_token	*token_c;

	head = t_dll_get_head(token_list);
	args = NULL;
	if (((t_token *)head->content)->type != TOKEN_COMMAND)
		return (NULL);
	while (head)
	{
		token_c = (t_token *)head->content;
		if (!head->prev || !token_is_redirection((t_token *)head->prev->content))
		{
			if (token_c->type == TOKEN_ARGUMENT)
				t_dll_add_back(&args, t_dll_new(create_arg(token_c)));
		}
		if (token_c->type == TOKEN_FLAG)
				t_dll_add_back(&args, t_dll_new(create_arg(token_c)));
		head = head->next;
	}
	return (args);
}

t_cmd	*ft_get_cmd(t_dll *token_list)
{
	t_cmd	*cmd;
	t_dll	*head;

	head = t_dll_get_head(token_list);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	if (((t_token *)head->content)->type == TOKEN_COMMAND)
		cmd->name = ft_strdup(((t_token *)head->content)->value);
	else
		cmd->name = NULL;
	cmd->arguments = get_arguments(head);
	return (cmd);
}