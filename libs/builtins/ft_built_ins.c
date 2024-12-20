/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_ins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_ins.h"

bool	ft_is_built_in(char *cmd, char **args, t_minishell *minishell)
{
	(void)minishell;
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		return (ft_echo(args), true);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (ft_cd(args, minishell), true);
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		return (ft_pwd(minishell), true);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		return (ft_export(args, minishell), true);
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		return (print_env(minishell->envs), true);
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		return (ft_unset(args, minishell), true);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		return (ft_exit(args, minishell), true);
	return (false);
}
