#include "ft_built_ins.h"

t_env	*t_env_new(char *key, char *value)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = ft_strdup(key);
	if (value)
		env->value = ft_strdup(value);
	else
		env->value = NULL;
	return (env);
}

void	print_env_declare(t_dll *envs)
{
	char	**aux_list;
	int		size;
	int		i;

	size = t_dll_size(envs);
	aux_list = create_aux_list(envs, size);
	sort_ascii(aux_list, size);
	i = 0;
	while (aux_list[i])
	{
		printf("declare -x %s\n", aux_list[i]);
		i++;
	}
	ft_free_char_array(aux_list);
}

void	process_env_var(char *arg, t_minishell *minishell, t_dll **envs)
{
	char	*key;
	char	*value;

	if (ft_strchr(arg, '=') == NULL)
	{
		key = ft_strdup(arg);
		value = NULL;
	}
	else
	{
		key = strndup(arg, ft_strchr(arg, '=') - arg);
		value = ft_strdup(ft_strchr(arg, '=') + 1);
	}
	if (ft_find_env(key, minishell->envs) && value)
		set_env_var(minishell, key, value);
	else if (ft_find_env(key, minishell->envs) == NULL)
		t_dll_add_back(envs, t_dll_new(t_env_new(key, value)));
	free(key);
	if (value)
		free(value);
}

void	ft_export(char **args, t_minishell *minishell)
{
	t_dll	**envs;

	if (!args[1])
	{
		print_env_declare(minishell->envs);
		return ;
	}
	args++;
	envs = &minishell->envs;
	while (*args && check_valid_env_var(*args))
	{
		process_env_var(*args, minishell, envs);
		args++;
	}
}
