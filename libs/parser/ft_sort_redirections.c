/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:28:26 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/11 22:31:14 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static long	get_last_input_index(t_dll *redirections)
{
	long	last_heredoc_index;
	t_dll	*head;

	last_heredoc_index = -1;
	head = t_dll_get_head(redirections);
	while (head)
	{
		if (((t_redir *)head->content)->type == REDIR_INPUT)
			last_heredoc_index = head->index;
		head = head->next;
	}
	return (last_heredoc_index);
}

static void	sort_heredoc(t_dll *redirections)
{
	long	last_heredoc_index;
	size_t	list_len;
	size_t	i;
	t_dll	*acn;

	last_heredoc_index = get_last_input_index(redirections);
	i = 0;
	list_len = t_dll_size(redirections);
	while (i < list_len)
	{
		acn = t_dll_get_node_index(redirections, i);
		if (((t_redir *)acn->content)->type == REDIR_HEREDOC)
		{
			last_heredoc_index++;
			t_dll_move_to(&redirections, acn->index, last_heredoc_index);
			i = last_heredoc_index + 1;
		}
		else
			i++;
	}
}

static void print_redirections(t_dll *red)
{
	t_dll *head = t_dll_get_head(red);
	t_redir *redir = NULL;
	printf("\n");
	while(head)
	{
		printf("\n");
		redir = (t_redir *)head->content;
		if (redir->type == REDIR_INPUT)
			printf("REDIR_INPUT");
		else if (redir->type == REDIR_OUTPUT)
			printf("REDIR_OUTPUT");
		else if (redir->type == REDIR_APPEND)
			printf("REDIR_APPEND");
		else if (redir->type == REDIR_HEREDOC)
			printf("REDIR_HEREDOC");
		printf(" %s", redir->file_path);
		printf(" delimiter: %s", redir->delimiter);
		printf("\n");
		head = head->next;
	}
	printf("\n");
}

static void	sort_input_redirection(t_dll *redirections)
{
	long	last_input_i;
	size_t	len;
	size_t	i;
	t_dll	*acn;

	last_input_i = -1;
	i = 0;
	len = t_dll_size(redirections);
	while (i < len)
	{
		acn = t_dll_get_node_index(redirections, i);
		if (((t_redir *)acn->content)->type == REDIR_INPUT)
		{
			last_input_i++;
			printf("\nFound input moving from %d to %d\n", (int)acn->index, (int)last_input_i);
			t_dll_move_to(&redirections, acn->index, last_input_i);
			print_redirections(redirections);
		}
		i++;
	}
}

void	ft_sort_redirections(t_dll *redirections)
{
	printf("\nsorting redirections\n");
	sort_input_redirection(redirections);
	sort_heredoc(redirections);
}