#include "ft_expander.h"

void	ft_expander(t_minishell *minishell)
{
	printf("\nHello from expander, envs %d", (int)t_dll_size(minishell->envs));
}