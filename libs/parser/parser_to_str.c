/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:12:38 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/08 07:52:51 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	print_single_arg(t_arg *arg, char *tab)
{
	char	*type;

	type = "";
	if (arg->type == STRING_DOUBLE)
		type = "STRING_DOUBLE";
	else if (arg->type == STRING_SINGLE)
		type = "STRING_SINGLE";
	else if (arg->type == FLAG)
		type = "FLAG";
	else
		type = "ARGUMENT";
	printf("\n%s\t\t{", tab);
	printf("\n%s\t\t\ttype: %s,", tab, type);
	printf("\n%s\t\t\tvalue: %s,", tab, arg->value);
	printf("\n%s\t\t},", tab);
}

void	print_args(t_dll *args, char *tab)
{
	t_dll	*head;

	head = t_dll_get_head(args);
	while (head)
	{
		print_single_arg((t_arg *)head->content, tab);
		head = head->next;
	}
}

void	print_redirections(t_dll *redirections, char *tab)
{
	char	*type;
	t_dll	*head;
	t_redir	*redir;

	head = t_dll_get_head(redirections);
	while (head)
	{
		if (((t_redir *)head->content)->type == REDIR_INPUT)
			type = "REDIR_INPUT";
		else if (((t_redir *)head->content)->type == REDIR_OUTPUT)
			type = "REDIR_OUTPUT";
		else if (((t_redir *)head->content)->type == REDIR_APPEND)
			type = "REDIR_APPEND";
		else
			type = "REDIR_HEREDOC";
		redir = (t_redir *)head->content;
		printf("\n%s\t\t{", tab);
		printf("\n%s\t\t\ttype: %s,", tab, type);
		printf("\n%s\t\t\tdelimiter: %s,", tab, redir->delimiter);
		printf("\n%s\t\t\tfile_path: %s,", tab, redir->file_path);
		printf("\n%s\t\t\tfd: %d,", tab, redir->fd);
		printf("\n%s\t\t},", tab);
		head = head->next;
	}
}

void	print_cmd(t_cmd *cmd, int indc)
{
	char	*tab;

	tab = "";
	while (indc > 0)
	{
		tab = ft_strjoin(tab, "\t");
		indc--;
	}
	printf("\n%s{\n%s\tname: %s,", tab, tab, cmd->name);
	printf("\n%s\targuments:\n%s\t[", tab, tab);
	print_args((t_dll *)cmd->arguments, tab);
	printf("\n%s\t],", tab);
	printf("\n%s\tredirections:\n%s\t[", tab, tab);
	print_redirections((t_dll *)cmd->redirections, tab);
	printf("\n%s\t],\n", tab);
	printf("\n%s},", tab);
}

void	print_pipe_seq(t_pipes *pipes)
{
	t_dll	*head;

	printf("\n\t\t\t{\n\t\t\t\tcmd_count: %d,", pipes->cmd_count);
	printf("\n\t\t\t\tcmds:\n\t\t\t\t[");
	head = t_dll_get_head(pipes->cmds);
	while (head)
	{
		printf("\n\t\t\t\t\t{%s},", (char *)head->content);
		head = head->next;
	}
	printf("\n\t\t\t\t]");
}

void	print_cmd_table(t_cmdt *cmd_table)
{
	char	*type;
	char	*obj_type;

	if (cmd_table->type == PIPE_SEQ)
		type = "PIPE_SEQ";
	else
		type = "COMMAND";
	if (cmd_table->type == PIPE_SEQ)
		obj_type = "t_pipes";
	else
		obj_type = "t_cmd";
	printf("\n\n____________\n\nParser output:\n\n");
	printf("t_cmdt:\n{\n	type : %s", type);
	printf("\n	content: %s\n", obj_type);
	if (cmd_table->type == PIPE_SEQ)
		print_pipe_seq((t_pipes *)cmd_table->content);
	else
		print_cmd((t_cmd *)cmd_table->content, 2);
	printf("\n}");
	printf("\n\n_____________\n\n");
}
