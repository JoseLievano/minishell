#include "ft_expander.h"

char	*handle_single_quotes(char *str, int *count)
{
	char	*result;

	(*count)++;
	while (str[*count] != '\'' && str[*count] != '\0')
		(*count)++;
	result = ft_substr(str, 1, *count - 1);
	return (result);
}

char	*handle_double_quotes(char *str, t_dll *envs, int last, int *count)
{
	char	*result;

	(*count)++;
	while (str[*count] != '\"' && str[*count] != '\0')
		(*count)++;
	result = expanding(ft_substr(str, 1, *count - 1), envs, last);
	return (result);
}

char	*handle_no_quotes(char *str, t_dll *envs, int last, int *count)
{
	char	*result;

	while (str[*count] != '\"' && str[*count] != '\0' && str[*count] != '\'')
		(*count)++;
	result = expanding(ft_substr(str, 0, *count), envs, last);
	(*count)--;
	return (result);
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
			tmp = new_str, new_str = ft_strjoin(new_str,
					handle_single_quotes(str, &count));
		else if (*str == '\"')
			tmp = new_str, new_str = ft_strjoin(new_str,
					handle_double_quotes(str, envs, last, &count));
		else
			tmp = new_str, new_str = ft_strjoin(new_str, handle_no_quotes(str,
						envs, last, &count));
		free(tmp);
		str += count + 1;
		count = 1;
	}
	return (new_str);
}
