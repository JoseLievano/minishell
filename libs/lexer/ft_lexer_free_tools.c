/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_free_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	free_token(t_dll *list)
{
	t_dll	*tmp;

	tmp = list;
	if (((t_token *)tmp->content)->value != NULL)
	{
		free(((t_token *)tmp->content)->value);
	}
	free(tmp->content);
}

void	free_nodes(t_dll *list)
{
	t_dll_clear(list, &free_token);
}
