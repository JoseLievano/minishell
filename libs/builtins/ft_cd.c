#include "ft_built_ins.h"

void	set_env_var(t_minishell *minishell, const char *key, const char *value)
{
	size_t	key_len;
	char	*new_var_value;
	t_dll	*envs;
	t_env	*env;
	char	*tmp;

	key_len = strlen(key);
	new_var_value = malloc(ft_strlen(value) + 2);
	if (!new_var_value)
		return ;
	envs = minishell->envs;
	ft_strlcpy(new_var_value, value, ft_strlen(value) + 1);
	while (envs)
	{
		env = envs->content;
		if (ft_strncmp(env->key, key, key_len) == 0)
		{
			tmp = env->value;
			env->value = new_var_value;
			free(tmp);
			return ;
		}
		envs = envs->next;
	}
	free(new_var_value);
}

void	change_directory(const char *path, t_minishell *minishell, char *og_pwd)
{
	if (chdir(path) == -1)
		printf("cd: %s: No such file or directory\n", path);
	else
	{
		set_env_var(minishell, "OLDPWD", og_pwd);
		set_env_var(minishell, "PWD", path);
	}
}

void	ft_cd(char **args, t_minishell *minishell)
{
	char	*og_pwd;
	char	*path;
	t_dll	*envs;
	t_env	*env;

	envs = ft_find_env("PWD", minishell->envs);
	env = envs->content;
	og_pwd = ft_strdup(env->value);
	if (!args[1])
	{
		envs = ft_find_env("HOME", minishell->envs);
		env = envs->content;
		change_directory(env->value, minishell, og_pwd);
	}
	else if (args[2])
		printf("cd: too many arguments\n");
	else
	{
		path = args[1];
		change_directory(path, minishell, og_pwd);
	}
	free(og_pwd);
}
