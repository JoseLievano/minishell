/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:53:42 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 16:54:14 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_dll	*clone_tk_node(t_dll *node)
{
	t_token	*token_content;

	token_content = (t_token *)malloc(sizeof(t_token));
	token_content->type = ((t_token *)node->content)->type;
	if (token_content->type == TOKEN_END_INPUT)
		token_content->value = NULL;
	else
		token_content->value = ft_strdup(((t_token *)node->content)->value);
	return (t_dll_new(token_content));
}
