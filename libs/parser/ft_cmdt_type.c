/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdt_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:55:25 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 11:59:09 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static bool has_pipes(t_dll *token_list)
{
    t_dll   *head;

    head = t_dll_get_head(token_list);
    while (head)
    {
        if (((t_token *)head->content)->type == TOKEN_PIPE)
            return (true);
        head = head->next;
    }
    return (false);
}

static void set_pipe_seq(t_cmdt *cmdt, t_dll *token_list)
{
    t_pipes *pipe_sequence;
    t_dll   *head;

    pipe_sequence = (t_pipes *)malloc(sizeof(t_pipes));
    head = t_dll_get_head(token_list);
    pipe_sequence->cmd_count = 1;
    while (head)
    {
        if (((t_token *)head->content)->type == TOKEN_PIPE)
            pipe_sequence->cmd_count++;
        head = head->next;
    }
    cmdt->content = pipe_sequence;
	cmdt->type = PIPE_SEQ;
}

void    ft_set_cmdt_type(t_cmdt *cmdt, t_dll *token_list)
{
	printf("\nSetting cmdt type\n");
	if (has_pipes(token_list))
	{
		printf("\nhas pipes\n");
		set_pipe_seq(cmdt, token_list);
	}
	else
	{
		cmdt->type = COMMAND;
		cmdt->content = ft_get_cmd(token_list);
	}
}
