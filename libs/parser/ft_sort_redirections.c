/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:28:26 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/11 22:31:14 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_sort_redirections(t_dll *redirections)
{
	long	last_input_i;
	size_t	len;
	size_t	i;
	t_dll	*acn;

	last_input_i = -1;
	i = 0;
	len = t_dll_size(redirections);
	while (i < len)
	{
		acn = t_dll_get_node_index(redirections, i);
		if (((t_redir *)acn->content)->type == REDIR_INPUT
			|| ((t_redir *)acn->content)->type == REDIR_HEREDOC)
		{
			last_input_i++;
			t_dll_move_to(&redirections, acn->index, last_input_i);
			redirections = t_dll_get_head(redirections);
		}
		i++;
	}
}
