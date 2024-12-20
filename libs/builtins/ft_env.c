/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_ins.h"

void	print_env(t_dll *envs)
{
	t_env	*env;

	while (envs)
	{
		env = envs->content;
		if (env->value)
			printf("%s=%s\n", env->key, env->value);
		envs = envs->next;
	}
}
