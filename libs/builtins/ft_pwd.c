/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_ins.h"

void	ft_pwd(t_minishell *minishell)
{
	t_dll	*envs;
	t_env	*env;

	envs = ft_find_env("PWD", minishell->envs);
	env = envs->content;
	printf("%s\n", env->value);
}
