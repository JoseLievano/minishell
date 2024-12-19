#include "ft_built_ins.h"

void	ft_pwd(t_minishell *minishell)
{
	t_dll	*envs;
	t_env	*env;

	envs = ft_find_env("PWD", minishell->envs);
	env = envs->content;
	printf("%s\n", env->value);
}
