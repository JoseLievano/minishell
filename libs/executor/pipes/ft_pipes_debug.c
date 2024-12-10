#include "../ft_executor.h"

static void print_args(char **args)
{
	while (*args)
	{
		printf("\n	%s", *args);
		args++;
	}
}

static void	print_pipe(t_dll *pipe)
{
	t_piped_cmd	*cmdpiped;

	cmdpiped = (t_piped_cmd *)pipe->content;
	printf("\n---------------");
	printf("\ncmd: %s", cmdpiped->cmd);
	print_args(cmdpiped->args);
	printf("\nPosition  %d", cmdpiped->position);
	printf("\nDef stdin : %d | Def stdout : %d", cmdpiped->def_stdin, cmdpiped->def_stdout);
	printf("\nNew stdin : %d | New stdout : %d", cmdpiped->new_stdin, cmdpiped->new_stdout);
	printf("\nExec result %d", cmdpiped->execve_result);
	printf("\n---------------\n");
}

void debug_pipes(t_piph *holder)
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
