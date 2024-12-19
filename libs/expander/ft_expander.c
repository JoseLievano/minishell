#include "ft_expander.h"

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

void	run_through_arguments(t_cmd *command_table, t_minishell *minishell)
{
	t_dll	*tmp;
	char	*tmp_arg;

	tmp_arg = command_table->name;
	command_table->name = breakdown(command_table->name, minishell);
	free(tmp_arg);
	tmp = command_table->arguments;
	while ((t_dll *)tmp)
	{
		if (((t_arg *)tmp->content)->value)
		{
			tmp_arg = ((t_arg *)tmp->content)->value;
			((t_arg *)tmp->content)->value = breakdown(tmp_arg, minishell);
			free(tmp_arg);
		}
		tmp = tmp->next;
	}
}

void	ft_expander(t_minishell *minishell)
{
	t_cmdt	*command_table;

	command_table = minishell->cmdt;
	if (command_table->type == PIPE_SEQ)
		return ;
	run_through_arguments(command_table->content, minishell);
}
