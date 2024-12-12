#include "ft_expander.h"

static char	*expand_variable(char *str, int *i, char **envs_array, int *j,
		int last)
{
	char	*new_str;

	new_str = ft_strdup("");
	if (str[*i] == '$' && str[*i + 1] == '?')
	{
		new_str = ft_strjoin(new_str, ft_itoa(last));
		*i += 2;
	}
	else
	{
		new_str = ft_strjoin(new_str, envs_array[*j]);
		while (str[*i] != ' ' && str[*i] != '\0')
			(*i)++;
		(*j)++;
	}
	return (new_str);
}

static char	*expand_char(char *str, int *i, char *new_str)
{
	char	*tmp;

	tmp = new_str;
	new_str = ft_strjoin_char(new_str, str[*i]);
	(*i)++;
	free(tmp);
	return (new_str);
}

static char	*expand_string(char *str, char **envs_array, int last)
{
	int		i;
	int		j;
	char	*new_str;
	char	*tmp;

	i = 0;
	j = 0;
	new_str = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			tmp = new_str;
			new_str = expand_variable(str, &i, envs_array, &j, last);
			free(tmp);
		}
		else
		{
			new_str = expand_char(str, &i, new_str);
		}
	}
	return (new_str);
}

char	*expanding(char *str, t_dll *envs, int last)
{
	char	**envs_array;
	char	*new_str;

	if (count_env(str) != 0)
	{
		envs_array = get_envs(str, envs);
		new_str = expand_string(str, envs_array, last);
		return (new_str);
	}
	return (ft_strdup(str));
}
