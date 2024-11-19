#include "ft_expander.h"

void	ft_expander(t_minishell *minishell)
{
	printf("\nHello from expander, envs %d", (int)t_dll_size(minishell->envs));
	t_dll *path_node = ft_find_env("PATH", minishell->envs);
	printf("\nPath value: %s", ((t_env *)path_node->content)->value);
}