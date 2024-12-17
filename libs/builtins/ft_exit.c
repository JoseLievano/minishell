#include "ft_built_ins.h"

void    ft_exit(char **args, t_minishell *minishell)
{
	int		exit_status;
	bool	should_exit;

	printf("exit\n");
	exit_status = minishell->last_output;
	should_exit = true;
	if (args && args[1])
	{
		printf("exit : too many arguments\n");
		minishell->last_output = 1;
		if (minishell->interactive_mode)
			should_exit = false;
		else
			exit_status = 1;
	}
	if (should_exit)
	{
		rl_clear_history();
		ft_clean_minishell(minishell);
		exit(exit_status);
	}
}