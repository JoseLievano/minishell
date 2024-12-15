/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:04:56 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/15 23:04:57 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static void	print_args(char **args)
{
	int	i;

	i = 1;
	while (*args)
	{
		printf("\n	%d - %s", i, *args);
		args++;
		i++;
	}
}

static void	print_pipe(t_dll *pipe)
{
	t_piped_cmd	*cmdpiped;

	cmdpiped = (t_piped_cmd *)pipe->content;
	printf("\n---------------");
	printf("\ncmd: %s", cmdpiped->cmd);
	printf("\nArgs: ");
	print_args(cmdpiped->args);
	printf("\nPosition  %d", cmdpiped->position);
	printf("\nDef stdin : %d | Def stdout : %d",
		cmdpiped->def_stdin, cmdpiped->def_stdout);
	printf("\nNew stdin : %d | New stdout : %d",
		cmdpiped->new_stdin, cmdpiped->new_stdout);
	printf("\nPosition : ");
	if (cmdpiped->position == PIPE_START)
		printf("PIPE_START");
	if (cmdpiped->position == PIPE_MIDDLE)
		printf("PIPE_MIDDLE");
	if (cmdpiped->position == PIPE_END)
		printf("PIPE_END");
	printf("\nExec result %d", cmdpiped->execve_result);
	printf("\n---------------\n");
}

void	debug_pipes(t_piph *holder)
{
	t_dll	*pipes;

	printf("\nPIPES DEBUGG\nCount : %d\n", holder->pipes_count);
	pipes = holder->pipes_cmd;
	while (pipes)
	{
		print_pipe(pipes);
		pipes = pipes->next;
	}
}
