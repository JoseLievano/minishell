/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:13:29 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/13 18:13:30 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void	exec_child(t_minishell *shell, char **args, char **envs, char *cmd)
{
	if (ft_process_exec_redirections(shell) == MOD_DUP_ERROR)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (execve(cmd, args, envs) == -1)
	{
		perror("Command error");
		exit(EXIT_FAILURE);
	}
}

int	pid_execution(t_minishell *shell, char **args, char **envs, char *cmd_path)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
		exec_child(shell, args, envs, cmd_path);
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}
		close_redirections(shell);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (-100);
}
