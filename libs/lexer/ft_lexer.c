/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/09 22:56:41 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"


bool is_whitespace(char c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == '\0')
		return (true);
	return (false);
}


void token_type(void)
{
	//return a number that represents the type of token
	char *string;
	if (string[0] == 124 && is_whitespace(string[1]))
	{
		//pipe TOKEN
	}
	if (string[0] == 45)
	{
		//flag TOKEN
	}

	if (string[0] == 62 && string[1] == 62 && is_whitespace(string[2]))
	{
		//output redirection append TOKEN
	}
	if (string[0] == 60 && string[1] == 60)
	{
		//input HEREDOC TOKEN
	}
	if (string[0] == 60 && is_whitespace(string[1]))
	{
		//input redirection TOKEN
	}
	if (string[0] == 62 && is_whitespace(string[1]))
	{
		//output redirection TOKEN
	}
	
	
	

	if (string[0] == 34)
	{
		//double quote TOKEN
	}
	if (string[0] == 39)
	{
		//single quote TOKEN
	}
	
	if (string[0] > 32 && string[0] < 127)
	{
		//command or argument TOKEN
	}
}

void list_N_tokens(void);

void assign_token(void)
{
	t_token *token = malloc(sizeof(t_token));
	token->value = "ls";
	printf("Token type: %s , %s\n", token->type, token->value);
	free(token);
}

void ft_lexer(void)
{
	printf("Lexer function\n");

}

