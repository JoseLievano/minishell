#include "ft_expander.h"

void	ft_expander(t_minishell *minishell)
{
	printf("\nHello from expander, envs %d", (int)t_dll_size(minishell->envs));
	t_cmdt *command_table = minishell->cmdt;
	if (command_table->type == PIPE_SEQ)
		return ;
	t_dll *path_node = ft_find_env("PATH", minishell->envs);
	t_env *result_env = (t_env *)path_node->content;
	printf("\nPath value: %s", result_env->value);
}