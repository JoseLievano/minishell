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
# include "../libs/builtins/ft_built_ins.h"
# include "../libs/executor/ft_executor.h"
# include <sys/wait.h>
# include <readline/history.h>
# include <stdio.h>
# include <readline/readline.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>

extern volatile sig_atomic_t	g_signal_received;

typedef struct command_table	t_cmdt;

typedef struct pipe_holder		t_piph;

typedef struct env_v_obj
{
	char	*key;
	char	*value;
}	t_env;

typedef struct minishell_obj
{
	t_cmdt	*cmdt;
	t_dll	*envs;
	t_piph	*pipe_holder;
	char	*line;
	char	*shell_path;
	char	*shell_dir;
	int		new_stdin;
	int		new_stdout;
	int		last_output;
	int		default_stdout;
	int		default_stdin;
	bool	interactive_mode;
}	t_minishell;

t_dll		*get_env_var_list(char **envp);
void		ft_set_shell_path(t_minishell *minishell);
t_minishell	*construct_minishell(char **envp);
void		ft_noninteractive_shell(t_minishell *minishell);
void		ft_parse_args(t_minishell *minishell, int argc, char **argv);
void		ft_interactive_shell(t_minishell *minishell);
void		ft_clean_minishell(t_minishell *minishell);
void		ft_partial_clean_minishell(t_minishell *minishell);
void		ft_setup_interactive_signals(void);
void		ft_setup_child_signals(void);
void		ft_setup_parent_signals(void);
bool		ft_check_eof(char *input);

#endif
