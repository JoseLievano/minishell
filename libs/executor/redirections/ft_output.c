/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:01:45 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/21 20:01:46 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

bool	ft_process_output(t_redir *redirection, t_minishell *minishell)
{
	char	*f_path;

	f_path = redirection->file_path;
	redirection->fd = open(f_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (redirection->fd == -1)
	{
		minishell->last_output = 1;
		return (false);
	}
	return (true);
}
