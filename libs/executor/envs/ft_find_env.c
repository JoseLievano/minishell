/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:49:47 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/19 17:49:47 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static int	key_comparator(void **args, int n_args)
{
	t_env	*env;
	int		result;
	t_dll	*node;
	char	*key;

	if (n_args == 0)
		return (0);
	node = args[0];
	key = args[1];
	env = (t_env *)node->content;
	if (ft_strlen(env->key) != ft_strlen(key))
		return (0);
	result = ft_strncmp(env->key, key, ft_strlen(key));
	if (result == 0)
		return (1);
	return (0);
}

void	ft_print_envs(t_dll *env_list)
{
	char	**envs;

	envs = ft_envs_to_array(env_list);
	while (*envs)
	{
		printf("\n%s", *envs);
		envs++;
	}
	ft_free_char_array(envs);
}

t_dll	*ft_find_env(char *key, t_dll *env_list)
{
	t_dll	*found_node;
	void	**args;

	args = (void *)malloc(sizeof(void *) * 2);
	args[0] = NULL;
	args[1] = key;
	found_node = t_dll_first_mtch(env_list, args, 2, &key_comparator);
	free(args);
	return (found_node);
}
