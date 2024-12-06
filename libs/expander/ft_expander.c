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
	// printf("\nNum_env: %d", count);
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

char	**get_envs(char *str, t_dll *envs)
{
	int		i;
	t_dll	*tmp;
	int		j;
	char	**envs_array;
	char	*word;
	t_env	*result_env;

	i = 0;
	j = 0;
	envs_array = (char **)malloc(sizeof(char *) * count_env(str) + 1);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			word = get_word(&str[i + 1]);
			tmp = ft_find_env(word, envs);
			if (tmp)
			{
				result_env = (t_env *)tmp->content;
				envs_array[j] = ft_strdup(result_env->value);
			}
			else
				envs_array[j] = ft_strdup("");
			j++;
			free(word);
		}
		i++;
	}
	return (envs_array);
}

char	*ft_strjoin_char(char *str, char c)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	return (new_str);
}

char	*expanding(char *str, t_dll *envs, int last)
{
	int		i;
	int		j;
		char *tmp;
	char	**envs_array;
	char	*new_str;

	if (count_env(str) != 0)
	{
		i = 0;
		j = 0;
		envs_array = get_envs(str, envs);
		new_str = ft_strdup("");
		while (str[i])
		{
			if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
			{
				tmp = new_str;
				if (str[i] == '$' && str[i + 1] == '?')
				{
					new_str = ft_strjoin(new_str, ft_itoa(last));
					i += 2;
				}
				else
				{
					new_str = ft_strjoin(new_str, envs_array[j]);
					while (str[i] != ' ' && str[i] != '\0')
						i++;
					j++;
				}
				free(tmp);
			}
			else
			{
				tmp = new_str;
				new_str = ft_strjoin_char(new_str, str[i]);
				i++;
				free(tmp);
			}
		}
		// printf("\nExpanded Argument: %s", new_str);
		return (new_str);
	}
	return (ft_strdup(str));
}

char	*quotes_breakdown_n_expantion(char *str, t_dll *envs, int last)
{
	int		count;
	char	*new_str;
	char	*tmp;

	count = 1;
	new_str = ft_strdup("");
	while (*str)
	{
		if (*str == '\'')
		{
			while (str[count] != '\'' && str[count] != '\0')
				count++;
			tmp = new_str;
			new_str = ft_strjoin(new_str, ft_substr(str, 1, count - 1));
		}
		else if (*str == '\"')
		{
			while (str[count] != '\"' && str[count] != '\0')
				count++;
			tmp = new_str;
			new_str = ft_strjoin(new_str, expanding(ft_substr(str, 1, count
							- 1), envs, last));
		}
		else
		{
			while (str[count] != '\"' && str[count] != '\0'
				&& str[count] != '\'')
				count++;
			tmp = new_str;
			new_str = ft_strjoin(new_str, expanding(ft_substr(str, 0, count),
						envs, last));
			count--;
		}
		free(tmp);
		str += count + 1;
		count = 1;
	}
	return (new_str);
}

void	run_through_arguments(t_cmd *command_table, t_dll *envs,
		int last_output)
{
	t_dll	*tmp;
	char	*tmp_arg;

	tmp_arg = command_table->name;
//	printf("\nCommand name: %s", command_table->name);
	command_table->name = expanding(command_table->name, envs, last_output);
//	printf("\nExpanded Command name: %s", command_table->name);
	free(tmp_arg);
	tmp = command_table->arguments;
	while ((t_dll *)tmp)
	{
		if (((t_arg *)tmp->content)->value)
		{
//			printf("\nArgument: %s", ((t_arg *)tmp->content)->value);
			tmp_arg = ((t_arg *)tmp->content)->value;
			((t_arg *)tmp->content)->value = quotes_breakdown_n_expantion(((t_arg *)tmp->content)->value,
					envs, last_output);
			free(tmp_arg);
//			printf("\nExpanded Argument: %s", ((t_arg *)tmp->content)->value);
		}
		tmp = tmp->next;
	}
//	printf("\n");
}

void	ft_expander(t_minishell *minishell)
{
	t_cmdt *command_table = minishell->cmdt;
	if (command_table->type == PIPE_SEQ)
		return ;
	run_through_arguments(command_table->content, minishell->envs,
		minishell->last_output);
}