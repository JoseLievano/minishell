/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_ins.h"

bool	check_valid_env_var(char *str)
{
	int	count_equals;
	int	i;

	i = 0;
	count_equals = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '='
			&& count_equals == 0)
		{
			printf("export: `%s': not a valid identifier\n", str);
			return (false);
		}
		if (str[i] == '=' && str[i + 1] != '\0' && i != 0)
			count_equals++;
		i++;
	}
	return (true);
}

char	*strndup(const char *s, size_t n)
{
	char	*new;
	size_t	i;

	new = malloc(n + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*join_n_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

char	**create_aux_list(t_dll *envs, int size)
{
	char	**aux_list;
	int		i;
	t_env	*env;

	aux_list = malloc(sizeof(char *) * (size + 1));
	if (!aux_list)
		return (NULL);
	i = 0;
	while (envs)
	{
		env = envs->content;
		if (!env->value)
			aux_list[i] = ft_strdup(env->key);
		else
		{
			aux_list[i] = ft_strjoin(env->key, "=\"");
			aux_list[i] = join_n_free(aux_list[i], env->value);
			aux_list[i] = join_n_free(aux_list[i], "\"");
		}
		envs = envs->next;
		i++;
	}
	aux_list[i] = NULL;
	return (aux_list);
}

void	sort_ascii(char **list, int size)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strncmp(list[i], list[j], ft_strlen(list[i])) > 0)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
			j++;
		}
		i++;
	}
}
