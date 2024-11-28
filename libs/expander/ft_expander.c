#include "ft_expander.h"

int count_env(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			count++;
		}
		i++;
	}
	//printf("\nNum_env: %d", count);
	return (count);
}

char * get_word(char *str)
{
	int i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	char *word = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';	
	return (word);
}

int get_envs_lenghts(char **envs)
{
	int i = 0;
	int tmp = 0;
	while (i < count_env(*envs))
	{
		tmp += ft_strlen(envs[i]);
		// printf("\nLenght: %d", i);
		i++;
	}
	return (tmp);
}

char **get_envs(char *str, t_dll *envs)
{
	int i = 0;
	t_dll *tmp;
	int j = 0;
	char **envs_array = (char **)malloc(sizeof(char *) * count_env(str) + 1);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			char *word = get_word(&str[i + 1]);
			//printf("\nWord: %s", word);
			tmp = ft_find_env(word, envs);
			if (tmp)
			{
				t_env *result_env = (t_env *)tmp->content;
				//printf("\nValue: %s", result_env->value);
				envs_array[j] = ft_strdup(result_env->value);
			}
			else
			{
				envs_array[j] = ft_strdup("");
			}
			j++;
			free(word);
		}
		i++;
	}
	return (envs_array);
}

char *ft_strjoin_char(char *str, char c)
{
	int i = 0;
	char *new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	return (new_str);
}

void expanding(char *str, t_dll *envs)
{
	if (count_env(str) != 0){
	int i = 0;
	int j = 0;
	char * tmp;
	char **envs_array = get_envs(str, envs);
	char *new_str = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			tmp = new_str;
			new_str = ft_strjoin(new_str, envs_array[j]);
			// printf("\nNew_str: %s", new_str);
			// printf("\nEnv: %s", envs_array[j]);
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			j++;
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
	printf("\nExpanded Argument: %s", new_str);
	}
}



void run_through_arguments(t_cmd *command_table, t_dll *envs)
{
	t_dll *tmp;
	printf("\nCommand name: %s", command_table->name);
	tmp = command_table->arguments;
	while ((t_dll *)tmp)
	{
		printf("\nArgument: %s", ((t_arg *)tmp->content)->value);
		expanding(((t_arg *)tmp->content)->value, envs);
		tmp = tmp->next;	
	}
	printf("\n");
}





void	ft_expander(t_minishell *minishell)
{
	t_cmdt *command_table = minishell->cmdt;
	if (command_table->type == PIPE_SEQ)
		return ;
	run_through_arguments(command_table->content, minishell->envs);



	//t_dll *path_node = ft_find_env("PATH", minishell->envs);
	//t_env *result_env = (t_env *)path_node->content;
	//printf("\nPath value: %s", result_env->value);
}