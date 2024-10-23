/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:31 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/09 22:56:32 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H
# include "../../inc/minishell.h"

typedef struct s_token
{
    char           *type;
    char           *value;
} t_token;


void	ft_lexer(void);
void read_through_list(t_dll *list);
t_token *allocate_token(void);
void list_tokens(t_dll **list, t_token *token);
int is_valid_operator(char *string);
bool is_whitespace(char c);
int token_smr(char *string);
void token_type(int token_kind, t_token *token, t_dll **list);
void is_quote(char *string, int *i);
void token_check_n_assignment(char *string, int *word_counter);
t_dll *read_through_input(char *input);
void free_nodes(t_dll *list);
void	free_token(t_dll *list);
# endif
