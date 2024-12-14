#include "ft_expander.h"

static char *handle_dollar(char *str, int *i, char *new_str, char **envs_array, int *j, int last)
{
    char *tmp;

    if (str[*i] == '$' && str[*i + 1] == '?')
    {
        tmp = new_str;
        new_str = ft_strjoin(new_str, ft_itoa(last));
        *i += 2;
    }
    else
    {
        tmp = new_str;
        new_str = ft_strjoin(new_str, envs_array[*j]);
        while (str[*i] != ' ' && str[*i] != '\0')
            (*i)++;
        (*j)++;
    }
    free(tmp);
    return new_str;
}

static char *process_string(char *str, char **envs_array, int last)
{
    int i = 0;
    int j = 0;
    char *new_str = ft_strdup("");
    char *tmp;

    while (str[i])
    {
        if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '\0')
            new_str = handle_dollar(str, &i, new_str, envs_array, &j, last);
        else
        {
            tmp = new_str;
            new_str = ft_strjoin_char(new_str, str[i]);
            i++;
            free(tmp);
        }
    }
    return new_str;
}

char *expanding(char *str, t_dll *envs, int last)
{
    if (count_env(str) != 0)
    {
        char **envs_array = get_envs(str, envs);
        char *new_str = process_string(str, envs_array, last);
        return new_str;
    }
    return ft_strdup(str);
}
