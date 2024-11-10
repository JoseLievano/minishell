/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:28:26 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/10 14:04:15 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	sort_heredoc(t_dll *redirections)
{
	printf("hi %d", (int)redirections->index);
}

static void	sort_input_redirection(t_dll *redirections)
{
	printf("hi %d", (int)redirections->index);
}

void	ft_sort_redirections(t_dll *redirections)
{
	sort_input_redirection(redirections);
	sort_heredoc(redirections);
	printf("sort redirections %d", (int)t_dll_size(redirections));
}