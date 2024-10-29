/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_type_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:04:13 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/28 19:43:49 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"


bool	is_token_pipe(t_dll *node)
{
	t_token	*token;

	token = (t_token *)node;
	if (token->type == TOKEN_PIPE)
		return (true);
	return (false);
}

