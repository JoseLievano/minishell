#include "ft_expander.h"

char	*handle_single_quotes(char *str, int *count, char *new_str)
{
	char	*tmp;
	char	*tmp2;

	(*count)++;
	while (str[*count] != '\'' && str[*count] != '\0')
		(*count)++;
	if (str[*count] == '\'')
	{
		tmp = new_str;
		tmp2 = ft_substr(str, 1, *count - 1);
		new_str = ft_strjoin(new_str, tmp2);
		free(tmp);
		free(tmp2);
		(*count)++;
	}
	return (new_str);
}

char	*handle_double_quotes(char *str, int *count, char *new_str,
		t_minishell *minishell)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	(*count)++;
	while (str[*count] != '"' && str[*count] != '\0')
		(*count)++;
	if (str[*count] == '"')
	{
		tmp = new_str;
		tmp2 = ft_substr(str, 1, *count - 1);
		tmp3 = expanding(tmp2, minishell);
		new_str = ft_strjoin(new_str, tmp3);
		free(tmp);
		free(tmp2);
		free(tmp3);
		(*count)++;
	}
	return (new_str);
}

char	*handle_no_quotes(char *str, int *count, char *new_str,
		t_minishell *minishell)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	while (str[*count] != '\'' && str[*count] != '"' && str[*count] != '\0')
		(*count)++;
	tmp = new_str;
	tmp2 = ft_substr(str, 0, *count);
	tmp3 = expanding(tmp2, minishell);
	new_str = ft_strjoin(new_str, tmp3);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (new_str);
}

char	*loop(char *str, t_minishell *minishell, char *new_str)
{
	int	count;

	while (*str)
	{
		count = 0;
		if (*str == '\'')
		{
			new_str = handle_single_quotes(str, &count, new_str);
		}
		else if (*str == '"')
		{
			new_str = handle_double_quotes(str, &count, new_str, minishell);
		}
		else
		{
			new_str = handle_no_quotes(str, &count, new_str, minishell);
		}
		str += count;
	}
	return (new_str);
}

char	*breakdown(char *str, t_minishell *minishell)
{
	char	*new_str;

	new_str = ft_strdup("");
	new_str = loop(str, minishell, new_str);
	return (new_str);
}
