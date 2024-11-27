/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:22:50 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/21 20:22:51 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static bool	get_process_result(t_redir *redirection, t_minishell *minishell)
{
	bool	result;

	result = false;
	if (redirection->type == REDIR_OUTPUT)
		result = ft_process_output(redirection, minishell);
	else if (redirection->type == REDIR_APPEND)
		result = ft_process_append(redirection, minishell);
	else if (redirection->type == REDIR_INPUT)
		result = ft_process_input(redirection, minishell);
	else if (redirection->type == REDIR_HEREDOC)
		result = ft_process_heredoc(redirection, minishell);
	return (result);
}

bool	ft_process_redirections(t_minishell *minishell)
{
	t_dll	*rdr;
	int		errors;
	t_redir	*temp;

	rdr = t_dll_get_head(((t_cmd *)minishell->cmdt->content)->redirections);
	temp = NULL;
	errors = 0;
	if (t_dll_size(rdr) == 0)
		return (true);
	while (rdr)
	{
		temp = (t_redir *)rdr->content;
		if (!get_process_result(temp, minishell))
			errors++;
		if (errno == EACCES || errno == EROFS)
			break ;
		rdr = rdr->next;
	}
	if (errors > 0)
		return (false);
	return (true);
}
