/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 06:02:49 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/13 15:20:05 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdbool.h>
# include "../libs/libft/libft.h"
# include "../libs/t_dll/t_dll.h"
# include "../libs/reader/ft_reader.h"
# include "../libs/lexer/ft_lexer.h"
# include "../libs/parser/ft_parser.h"
# include "../libs/expander/ft_expander.h"
# include "../libs/executor/ft_executor.h"
# include <sys/wait.h>
# include <readline/history.h>
# include <stdio.h>
# include <readline/readline.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

typedef struct command_table	t_cmdt;

typedef struct env_v_obj
{
	char	*key;
	char	*value;
}	t_env;

typedef struct minishell_obj
{
	t_cmdt	*cmdt;
	t_dll	*envs;
	char	*line;
	char	*shell_path;
	char	*shell_dir;
	int		default_stdin;
	int		default_stdout;
	int		last_output;
}	t_minishell;

t_dll	*get_env_var_list(char **envp);
void	ft_set_shell_path(t_minishell *minishell);

#endif
