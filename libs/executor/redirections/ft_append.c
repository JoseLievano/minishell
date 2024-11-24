/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:01:21 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/21 20:01:22 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

bool	ft_process_append(t_redir *redirection, t_minishell *minishell)
{
	char	*f_path;

	f_path =  redirection->file_path;
	redirection->fd = open(f_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (redirection->fd == -1)
	{
		perror("¯\\(°_o)/¯ ERROR");
		minishell->last_output = errno;
		return (false);
	}
	return (true);
}
