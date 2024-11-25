/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:01:37 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/21 20:01:38 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

bool	ft_process_input(t_redir *input, t_minishell *minishell)
{
	char	*f_path;

	f_path = input->file_path;
	input->fd = open(f_path, O_RDONLY);
	if (input->fd == -1)
	{
		minishell->last_output = 1;
		return (false);
	}
	return (true);
}
