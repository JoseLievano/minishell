/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:44:08 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/08 19:49:35 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H
# include "../../inc/minishell.h"

typedef struct minishell_obj	t_minishell;
typedef struct redirection_obj	t_redir;

typedef enum modify_redirection
{
	MOD_IN,
	MOD_OUT,
	MOD_BOTH,
	MOD_NONE,
	MOD_DUP_ERROR
}	t_mod_red;

typedef enum pipe_position
{
	PIPE_START,
	PIPE_MIDDLE,
	PIPE_END,
	PIPE_UNDEFINED
}	t_pipe_position;

typedef struct pipe_obj
{
	char			*cmd;
	char			**args;
	pid_t			pid;
	t_pipe_position	position;
	int				def_stdin;
	int				def_stdout;
	int				new_stdin;
	int				new_stdout;
	int				execve_result;
}	t_piped_cmd;

typedef struct pipe_holder
{
	int		pipes_count;
	t_dll	*pipes_cmd;
}	t_piph;

void	ft_executor(t_minishell *minishell);
t_dll	*ft_find_env(char *key, t_dll *env_list);
char	**ft_envs_to_array(t_dll *env_list);
char	*ft_strjoin3(char *str1, char *str2, char *str3);
char	*ft_find_cmd_path(char *cmd, t_dll *envs);
void	ft_print_envs(t_dll *env_list);
int		ft_execute_cmd(t_minishell *minishell);
bool	ft_process_input(t_redir *redirection, t_minishell *minishell);
bool	ft_process_output(t_redir *redirection, t_minishell *minishell);
bool	ft_process_append(t_redir *redirection, t_minishell *minishell);
bool	ft_process_heredoc(t_redir *redirection, t_minishell *minishell);
bool	ft_process_redirections(t_minishell *minishell);
int		ft_process_exec_redirections(t_minishell *minishell);
int		get_exec_input_redirection(t_minishell *minishell);
int		get_exec_out_redirection(t_minishell *minishell);
bool	ft_pipe_holder_constructor(t_minishell *minishell);
void	ft_setup_piped_cmd_position(t_dll *piped_cmd);
bool	ft_setup_pipes_fds(t_piph *holder);
int		ft_execute_pipes(t_minishell *minishell);

#endif
