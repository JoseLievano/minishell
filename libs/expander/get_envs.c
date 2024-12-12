#include "ft_expander.h"

int	count_env(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*get_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	*get_env_value(char *str, t_dll *envs)
{
	char	*word;
	t_dll	*tmp;
	t_env	*result_env;
	char	*env_value;

	word = get_word(str);
	tmp = ft_find_env(word, envs);
	if (tmp)
	{
		result_env = (t_env *)tmp->content;
		env_value = ft_strdup(result_env->value);
	}
	else
		env_value = ft_strdup("");
	free(word);
	return (env_value);
}

char	**get_envs(char *str, t_dll *envs)
{
	int		i;
	int		j;
	char	**envs_array;

	i = 0;
	j = 0;
	envs_array = (char **)malloc(sizeof(char *) * count_env(str) + 1);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			envs_array[j] = get_env_value(&str[i + 1], envs);
			j++;
		}
		i++;
	}
	return (envs_array);
}
