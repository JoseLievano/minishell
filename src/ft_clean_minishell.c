/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:16:29 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/15 13:16:29 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	clean_shell_envs(t_dll *node)
{
	t_env	*env;

	if (!node->content)
		return ;
	env = (t_env *)node->content;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(node->content);
}

static void	clean_and_null(char *str)
{
	free(str);
	str = NULL;
}

void ft_clean_minishell(t_minishell *minishell)
{
    if (!minishell)
        return;

    if (minishell->cmdt)
    {
        ft_clean_cmdt(minishell->cmdt);
        minishell->cmdt = NULL;
    }
    if (minishell->pipe_holder)
    {
        ft_clean_pipe_holder(minishell);
        minishell->pipe_holder = NULL;
    }
    if (minishell->envs)
    {
        t_dll_clear(minishell->envs, &clean_shell_envs);
        minishell->envs = NULL;
    }
    if (minishell->line)
    	clean_and_null(minishell->line);
    if (minishell->shell_path)
    	clean_and_null(minishell->shell_path);
    if (minishell->shell_dir)
    	clean_and_null(minishell->shell_dir);
    free(minishell);
}

void ft_partial_clean_minishell(t_minishell *minishell)
{
    if (!minishell)
        return;
    if (minishell->cmdt)
    {
        ft_clean_cmdt(minishell->cmdt);
        minishell->cmdt = NULL;
    }
    if (minishell->pipe_holder)
    {
        ft_clean_pipe_holder(minishell);
        minishell->pipe_holder = NULL;
    }
    if (minishell->line)
    {
        free(minishell->line);
        minishell->line = NULL;
    }
}
