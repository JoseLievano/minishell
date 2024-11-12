/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:07:15 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/08 19:49:14 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (argc > 1 && *argv[1] == '2')
		ft_lexer();
	else if (argc > 1 && *argv[1] == '3')
		ft_parser(read_through_input(ft_reader()));
	else if (argc > 1 && *argv[1] == '4')
		ft_expander();
	else if (argc > 1 && *argv[1] == '5')
		ft_executor();
	return (0);
}
