/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:59:23 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/07 13:39:24 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_cmdt	*ft_parser(t_dll *token_list)
{
	t_cmdt	*cmdt;

	if (valid_syntax(token_list))
	{
		cmdt = ft_get_cmdt(token_list);
		return (cmdt);
	}
	else
	{
		printf("Invalid syntax");
		return (NULL);
	}
}
