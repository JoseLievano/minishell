/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	*allocate_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
	{
		printf("Error: Token allocation failed\n");
		exit(1);
	}
	token->value = NULL;
	return (token);
}

void	list_tokens(t_dll **list, t_token *token)
{
	t_dll_add_back(list, t_dll_new(token));
}

void	token_type(int token_kind, t_token *token, t_dll **list)
{
	static int	flag = 0;

	if (token_kind == 42)
	{
		flag = 0;
		return ;
	}
	if (token_kind >= 2 && token_kind <= 5)
		flag += 1;
	if ((token_kind == 7) && flag == 0)
	{
		flag = 1;
		token->type = 8;
		list_tokens(list, token);
		return ;
	}
	else if (token_kind == 1)
		flag = 0;
	token->type = token_kind;
	list_tokens(list, token);
}

void	token_check_n_assignment(char *string, int *word_counter)
{
	if (is_valid_operator(string) == 2 || is_valid_operator(string) == 3)
	{
		*word_counter = 2;
		return ;
	}
	else
		*word_counter = 0;
	while (is_valid_operator(string + *word_counter) == 0
		&& is_whitespace(string[*word_counter]) == false)
	{
		if (*(string + *word_counter) == 34 || *(string + *word_counter) == 39)
			*word_counter += is_closed_quote(string);
		else
			(*word_counter)++;
	}
	if (*word_counter == 0)
		*word_counter = 1;
}

t_dll	**allocate_dll(void)
{
	t_dll	**list;

	list = (t_dll **)malloc(sizeof(t_dll *));
	if (!list)
	{
		printf("Error: List allocation failed\n");
		exit(1);
	}
	*list = NULL;
	return (list);
}
