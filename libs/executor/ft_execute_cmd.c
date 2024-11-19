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

void	ft_execute_cmd(t_minishell *minishell)
{
	t_cmdt	*cmdt;

	cmdt = minishell->cmdt;
	printf("\nCMD: %s | envs: %d\n", ((t_cmd *)cmdt->content)->name, (int)t_dll_size(minishell->envs));
}
