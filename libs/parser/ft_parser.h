/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:29 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/25 13:07:36 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "../../inc/minishell.h"

typedef enum cmd_tab_type
{
	PIPE_SEQ,
	COMMAND
} t_cmd_type;

typedef enum redirection_type
{
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC
} t_redir_type;

typedef enum argument_type
{
	ARGUMENT,
	FLAG,
	STRING_DOUBLE,
	STRING_SINGLE
} t_arg_type;

typedef struct command_table
{
	t_cmd_type	type;
	void		*content;
} t_cmdt;

typedef struct pipe_sequence
{
	char	*name;
	int		cmd_count;
	t_dll	*cmds;
} t_pipes;

typedef struct redirection_obj
{
	t_redir_type	type;
	char			*delimiter;
	char			*file_path;
	int				fd;
};

typedef struct command_obj
{
	char	*name;
	t_dll	*arguments;
	t_dll	*flags;
	t_dll	*redirections;
} t_cmd;

void	ft_parser(void);
#endif

