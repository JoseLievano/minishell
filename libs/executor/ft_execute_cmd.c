/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:07 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/19 14:33:08 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static char	**get_args_to_execute(t_cmd *cmd)
{
	char	**args;
	size_t	len;
	size_t	i;
	size_t	j;
	t_dll	*args_node;

	i = 0;
	j = 0;
	args_node= t_dll_get_head(cmd->arguments);
	len = t_dll_size(args_node) + 2;
	args = (char **)malloc(sizeof(char *) * len);
	args[i] = ft_strdup(cmd->name);
	i++;
	while (i < len)
	{
		args_node= t_dll_get_node_index(args_node, j);
		if (!args_node)
			break ;
		args[i] = ft_strdup(((t_arg *)args_node->content)->value);
		i++;
		j++;
	}
	args[i] = NULL;
	return (args);
}

void	ft_print_envs(t_dll *env_list)
{
	char **envs = ft_envs_to_array(env_list);
	while(*envs)
	{
		printf("\n%s", *envs);
		free(*envs);
		envs++;
	}
}

void	ft_execute_cmd(t_minishell *minishell)
{
	char	**args;
	t_cmd	*cmd;

	cmd = (t_cmd *)minishell->cmdt->content;
	args = get_args_to_execute(cmd);
	printf("\n[");
	while (*args)
	{
		printf("%s,", *args);
		args++;
	}
	printf("%s]\n", *args);
	printf("\n");
	char *cmd_path = ft_find_cmd_path(cmd->name, minishell->envs);
	printf("\ncmd path: %s\n", cmd_path);
	print_envs(minishell->envs);
}
