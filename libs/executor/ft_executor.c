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

void ft_executor(t_minishell *minishell)
{
	t_cmdt	*cmdt;

	cmdt = minishell->cmdt;
	if (cmdt->type == COMMAND)
	{
		if (ft_process_redirections(minishell))
		{
			printf("\nRedirections setted");
			minishell->last_output = ft_execute_cmd(minishell);
		}
		else
			perror("¯\\(°_o)/¯ ERROR");
		printf("\n exec result %d \n", minishell->last_output);
		printf("\n----------\n");
	}
	else
		return ;
}