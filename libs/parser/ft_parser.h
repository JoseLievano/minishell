/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:29 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/25 12:50:21 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "../../inc/minishell.h"

typedef enum cmd_tab_type
{
	PIPE_SEQ,
	COMMAND
} t_cmdtype;

typedef struct command_table
{
	t_cmdtype	type;
	void		*content;
} t_cmdt;

typedef struct pipe_sequence
{
	char	*name;
	int		cmd_count;
	t_dll	*commands;
} t_pipes;

typedef struct command_obj
{
	char	*name;
	t_dll	*arguments;
	t_dll	*flags;
	t_dll	*redirections;
} t_cmd;

void	ft_parser(void);
#endif

