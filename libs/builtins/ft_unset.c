/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_ins.h"

void	free_env(t_env *env)
{
	free(env->key);
	free(env->value);
	free(env);
}

void	ft_dll_remove(t_dll **dll, t_dll *node)
{
	t_dll	*tmp;

	if (!node)
		return ;
	if (node == *dll)
	{
		*dll = node->next;
		if (node->next)
			node->next->prev = NULL;
	}
	else
	{
		tmp = node->prev;
		if (tmp)
			tmp->next = node->next;
		if (node->next)
			node->next->prev = tmp;
	}
	free_env(node->content);
	free(node);
}

void	ft_unset(char **args, t_minishell *minishell)
{
	t_dll	*envs;
	t_dll	*tmp;
	int		i;

	envs = minishell->envs;
	i = 1;
	while (args[i])
	{
		tmp = envs;
		if (ft_find_env(args[i], envs))
		{
			tmp = ft_find_env(args[i], envs);
			ft_dll_remove(&envs, tmp);
		}
		i++;
	}
}
