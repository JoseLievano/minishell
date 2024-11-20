/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envs_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:04:52 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/20 17:04:54 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static char	*get_env_str(t_dll *node)
{
	t_env	*env;

	env = (t_env *)node->content;
	return (ft_strjoin3(env->key, "=", env->value));
}

char	**ft_envs_to_array(t_dll *env_list)
{
	char	**envs;
	t_dll	*node;
	int		i;

	envs = (char **)malloc(sizeof(char *) * (t_dll_size(env_list) + 1));
	if (!envs)
		return (NULL);
	node = t_dll_get_head(env_list);
	i = 0;
	while (node)
	{
		envs[i] = get_env_str(node);
		i++;
		node = node->next;
	}
	envs[i] = NULL;
	return (envs);
}