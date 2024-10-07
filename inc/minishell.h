/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:48 by jlievano          #+#    #+#             */
/*   Updated: 2024/09/25 16:52:49 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libs/libft/libft.h"
# include "../libs/t_dll/t_dll.h"
# include "../libs/reader/ft_reader.h"
# include <readline/history.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

//Example
typedef struct command_table
{
    char            *type; //Pipe list, Command, redirection
    char            *command; //like echo, grep, awk etc...
    char            *args; //like "hello " or '{print $2}'
    char            *redirection_type; // < > >>
    char            *input;
    char            *output;
    t_dll           *command_list; //List of commands or NULL
}t_cmdtab;

#endif