/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:32:21 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/04 11:32:22 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_parse_args(t_minishell *minishell, int argc, char **argv)
{
	if (argc != 3)
		return ;
	if (ft_strncmp(argv[1], "-c", 2) != 0
		|| ft_strlen(argv[1]) != 2)
		return ;
	minishell->line = ft_strdup(argv[2]);
	minishell->interactive_mode = false;
}
