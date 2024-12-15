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
	char	*sub_str;

	(*count)++;
	while (str[*count] != '\"' && str[*count] != '\0')
		(*count)++;
	sub_str = ft_substr(str, 1, *count - 1);
	result = expanding(sub_str, envs, last);
	if (sub_str)
		free(sub_str);
	return (result);
}

char	*handle_no_quotes(char *str, t_dll *envs, int last, int *count)
{
	char	*result;
	char 	*sub_str;

	while (str[*count] != '\"' && str[*count] != '\0' && str[*count] != '\'')
		(*count)++;
	sub_str = ft_substr(str, 0, *count);
	result = expanding(sub_str, envs, last);
	if (sub_str)
		free(sub_str);
	(*count)--;
	return (result);
}

char	*quotes_breakdown_n_expantion(char *str, t_dll *envs, int last)
{
	int		count;
	char	*new_str;
	char	*tmp;
	char *tmp2;
	count = 1;
	new_str = ft_strdup("");
	while (*str)
	{
		if (*str == '\'')
		{
			tmp = new_str;
			tmp2 = handle_single_quotes(str, &count);
			new_str = ft_strjoin(new_str, tmp2);

		}else if (*str == '\"')
		{
			tmp = new_str;
			tmp2 = handle_double_quotes(str, envs, last, &count);
			new_str = ft_strjoin(new_str, tmp2);
		}
		else{
		tmp = new_str; 
		tmp2 = handle_no_quotes(str, envs, last, &count);
		new_str = ft_strjoin(new_str, tmp2);
		}
		free(tmp);
		free(tmp2);
		str += count + 1;
		count = 1;
	}
	return (new_str);
}
