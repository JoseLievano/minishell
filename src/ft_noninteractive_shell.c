/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noninteractive_shell.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:41:54 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/04 11:41:55 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_noninteractive_shell(t_minishell *minishell)
{
	t_dll	*token_list;

	minishell->interactive_mode = false;
	token_list = read_through_input(minishell->line);
	minishell->cmdt = ft_parser(token_list);
	ft_expander(minishell);
	if (minishell->cmdt)
		ft_executor(minishell);
	free_nodes(token_list);
	ft_clean_minishell(minishell);
}
