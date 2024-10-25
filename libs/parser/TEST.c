/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:26:09 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/25 18:26:10 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_cmdt *test1(void)
{
	return NULL;
}

t_cmdt	*get_test(int test_num)
{
	if (test_num == 1)
		return test1();
	return NULL;
}
