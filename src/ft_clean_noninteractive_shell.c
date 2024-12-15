/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_noninteractive_shell.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:48:36 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/15 12:48:36 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_clean_non_interactive_shell(t_minishell *minishell)
{
	printf("in the cleanr, %d ", minishell->default_stdin);
}
