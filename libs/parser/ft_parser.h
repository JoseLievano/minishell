/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:29 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/24 07:44:32 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "../../inc/minishell.h"

typedef struct command_table
{
	char	*type;
	void	*content;
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

