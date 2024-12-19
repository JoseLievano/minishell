#include "ft_expander.h"

static char	*handle_last(char **str, char *new_str, int last)
{
	char	*tmp;

	tmp = new_str;
	new_str = ft_strjoin(new_str, ft_itoa(last));
	(*str) += 2;
	free(tmp);
	return (new_str);
}

static char	*handle_dollar(char **str, char *new_str, char **envs_array, int *j)
{
	char	*tmp;

	tmp = new_str;
	new_str = ft_strjoin(new_str, envs_array[*j]);
	while (**str != ' ' && **str != '\0')
		(*str)++;
	(*j)++;
	free(tmp);
	return (new_str);
}

static char	*process_string(char *str, char **envs_array, int last)
{
	int		j;
	char	*new_str;
	char	*tmp;

	j = 0;
	new_str = ft_strdup("");
	while (*str)
	{
		if (*str == '$' && str[1] != ' ' && str[1] != '\0')
		{
			if (*str == '$' && str[1] == '?')
				new_str = handle_last(&str, new_str, last);
			else
				new_str = handle_dollar(&str, new_str, envs_array, &j);
		}
		else
		{
			tmp = new_str;
			new_str = ft_strjoin_char(new_str, *str);
			str++;
			free(tmp);
		}
	}
	return (new_str);
}

char	*expanding(char *str, t_minishell *minishell)
{
	t_dll	*envs;
	int		last;
	char	**envs_array;
	char	*new_str;

	envs = minishell->envs;
	last = minishell->last_output;
	if (count_env(str) != 0)
	{
		envs_array = get_envs(str, envs);
		new_str = process_string(str, envs_array, last);
		return (new_str);
	}
	return (ft_strdup(str));
}
