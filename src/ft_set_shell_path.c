/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_shell_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:04:34 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/25 00:04:36 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_set_shell_path(t_minishell *minishell)
{
	char	*shell_path;
	char	*shell_dir;
	t_dll	*pwd;

	pwd = ft_find_env("PWD", minishell->envs);
	shell_path = ft_strjoin(((t_env *)pwd->content)->value, "/minishell");
	minishell->shell_path = shell_path;
	shell_dir = ft_strjoin(((t_env *)pwd->content)->value, "/");
	minishell->shell_dir = shell_dir;
}
