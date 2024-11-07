/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdt_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:55:25 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 14:11:37 by jlievano         ###   ########.fr       */
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

static t_dll	*clone_tk_node(t_dll *node)
{
	t_token	*token_content;

	token_content = (t_token *)malloc(sizeof(t_token));
	token_content->type = ((t_token *)node->content)->type;
	if (token_content->type == TOKEN_END_INPUT)
		token_content->value = NULL;
	else
		token_content->value = ft_strdup(((t_token *)node->content)->value);
	return (t_dll_new(token_content));
}

static t_dll	*get_cmd_list(t_dll *token_list)
{
	t_dll	*head;
	t_dll	*cmd_list;
	t_dll	*temp_list;

	int		i;
	int		j;
	head = t_dll_get_head(token_list);
	cmd_list = NULL;
	i = 0;
	j = 0;
	while (head)
	{
		if (((t_token *)head->content)->type == TOKEN_PIPE || ((t_token *)head->content)->type == TOKEN_END_INPUT)
		{
			temp_list = t_dll_clone_range(token_list, i, j, &clone_tk_node);
			t_dll_add_back(&cmd_list, t_dll_new(ft_get_cmd(temp_list)));
			i = j + 1;
		}
		j++;
		head = head->next;
	}
	return (cmd_list);
}

static void set_pipe_seq(t_cmdt *cmdt, t_dll *token_list)
{
    t_pipes *pipe_sequence;
    //t_dll   *head;

    pipe_sequence = (t_pipes *)malloc(sizeof(t_pipes));
    //head = t_dll_get_head(token_list);
	pipe_sequence->cmds = get_cmd_list(token_list);
	pipe_sequence->cmd_count = (int)t_dll_size(pipe_sequence->cmds);
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
