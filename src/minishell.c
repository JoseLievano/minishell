/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:43 by jlievano          #+#    #+#             */
/*   Updated: 2024/09/25 16:52:44 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && *argv[1] == '1')
		ft_reader();
	if (argc > 1 && *argv[1] == '2')
		ft_lexer();
	return (0);
}
