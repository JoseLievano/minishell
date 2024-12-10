/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:43:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/13 12:11:18 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

void	ft_executor(t_minishell *minishell)
{
	t_cmdt	*cmdt;

	cmdt = minishell->cmdt;
	if (cmdt->type == COMMAND)
	{
		if (ft_process_redirections(minishell))
			minishell->last_output = ft_execute_cmd(minishell);
		else
			perror("¯\\(°_o)/¯ ERROR");
	}
	else if (cmdt->type == PIPE_SEQ)
	{
		minishell->last_output = ft_execute_pipes(minishell);
		if (minishell->last_output != 0)
			perror("¯\\(°_o)/¯ ERROR");
	}
	else
		return ;
}
