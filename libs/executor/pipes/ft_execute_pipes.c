/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:46:48 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/09 14:46:49 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

int	ft_execute_pipes(t_minishell *minishell)
{
	if (!ft_pipe_holder_constructor(minishell))
		return (1);
	else
		return (0);
}

/*
static void close_pipes(int pipe_fds[2])
{
    close(pipe_fds[0]);
    close(pipe_fds[1]);
}

static void execute_command(t_piped_cmd *cmd, t_minishell *minishell)
{
    if (execve(cmd->args[0], cmd->args, ft_envs_to_array(minishell->envs)) == -1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

int ft_execute_pipes(t_minishell *minishell)
{
    t_dll *current;
    int pipe_fds[2];
    int prev_fd = -1;
    pid_t pid;

    current = t_dll_get_head(minishell->pipe_holder->pipes_cmd);
    while (current)
    {
        t_piped_cmd *cmd = (t_piped_cmd *)current->content;
        if (current->next && pipe(pipe_fds) == -1)
            return (1);

        if ((pid = fork()) == -1)
            return (1);

        if (pid == 0)
        {
            if (prev_fd != -1)
            {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (current->next)
            {
                dup2(pipe_fds[1], STDOUT_FILENO);
                close_pipes(pipe_fds);
            }
            execute_command(cmd, minishell);
        }
        else
        {
            if (prev_fd != -1)
                close(prev_fd);
            if (current->next)
            {
                close(pipe_fds[1]);
                prev_fd = pipe_fds[0];
            }
            else
                close(pipe_fds[0]);
            current = current->next;
        }
    }
    while (wait(NULL) > 0);
    return (0);
}
*/