/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactive_shell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:47:15 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/04 11:47:16 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_interactive_shell(t_minishell *minishell)
{
    char    *input;
    t_dll   *token_list;
    int     exit_status;

    ft_setup_interactive_signals();
    while (1)
    {
        input = ft_reader();
        if (!input) // Ctrl-D case
        {
            exit_status = minishell->last_output; // Store the status before cleanup
            printf("exit\n");
            rl_clear_history();
            ft_clean_minishell(minishell);
            exit(exit_status); // Use stored status instead of accessing freed memory
        }
        if (*input)
        {
            add_history(input);
            token_list = read_through_input(input);
            if (token_list)
            {
                minishell->line = input;
                minishell->cmdt = ft_parser(token_list);
                if (minishell->cmdt)
                {
                    ft_expander(minishell);
                    ft_executor(minishell);
                }
                ft_partial_clean_minishell(minishell);
                free_nodes(token_list);
            }
            else
                free(input);
        }
        else
            free(input);
    }
}
