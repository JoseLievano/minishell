#include "ft_built_ins.h"

void	print_env(t_dll *envs)
{
	t_env	*env;

	while (envs)
	{
		env = envs->content;
		printf("%s=%s\n", env->key, env->value);
		envs = envs->next;
	}
}