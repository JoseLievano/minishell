/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:31 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/28 17:39:56 by glicciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H
# include "../../inc/minishell.h"


typedef enum  token_type
{
	TOKEN_END_INPUT,
	TOKEN_PIPE,
	TOKEN_REDIRECTION_APPEND,
	TOKEN_TOKEN_HEREDOC,
	TOKEN_REDIRECTION_IN,
	TOKEN_REDIRECTION_OUT,
	TOKEN_FLAG,
	TOKEN_STRING_DOUBLE,
	TOKEN_STRING_SINGLE,
	TOKEN_ARGUMENT,
    TOKEN_COMMAND
}	t_token_type;


typedef struct s_token
{
    t_token_type           type;
    char           *value;
} t_token;



void	ft_lexer(void);
void read_through_list(t_dll *list);
t_token *allocate_token(void);
void list_tokens(t_dll **list, t_token *token);
t_token_type is_valid_operator(char *string);
bool is_whitespace(char c);
t_token_type token_smr(char *string);
void token_type(int token_kind, t_token *token, t_dll **list);
void is_quote(char *string, int *i);
void token_check_n_assignment(char *string, int *word_counter);
t_dll *read_through_input(char *input);
void free_nodes(t_dll *list);
void	free_token(t_dll *list);
void is_quote_allocation(char **string, t_token *current_token);
# endif
