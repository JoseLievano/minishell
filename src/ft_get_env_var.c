/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envvar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:01:41 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/15 13:01:42 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static size_t	get_equals_index(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (i);
}

static t_env	*get_env_obj(char *key, char *value)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = key;
	env->value = value;
	return (env);
}

static t_dll	*get_env_node(char *str)
{
	size_t	first_equals_index;
	size_t	key_length;
	size_t	value_length;
	char	*key;
	char	*value;

	first_equals_index = get_equals_index(str);
	key_length = first_equals_index - 1;
	value_length = ft_strlen(str) - first_equals_index;
	key = ft_substr(str, 0, key_length + 1);
	value = ft_substr(str, first_equals_index + 1, value_length);
	return (t_dll_new(get_env_obj(key, value)));
}

static void	add_oldwpd(t_dll *env_list)
{
	t_dll	*old_wpd;
	char	*key;
	char	*value;

	env_list = t_dll_get_head(env_list);
	key = ft_strdup("OLDPWD");
	value = ft_strdup(" ");
	old_wpd = t_dll_new(get_env_obj(key, value));
	t_dll_add_back(&env_list, old_wpd);
}

t_dll	*get_env_var_list(char **envp)
{
	t_dll	*env_list;

	env_list = NULL;
	while (*envp)
	{
		t_dll_add_back(&env_list, get_env_node(*envp));
		envp++;
	}
	add_oldwpd(env_list);
	return (env_list);
}
