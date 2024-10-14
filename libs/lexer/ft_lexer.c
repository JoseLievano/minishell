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

int		is_valid_operator(char *string);
bool	is_whitespace(char c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13
		|| c == '\0')
		return (true);
	return (false);
}

int	token_smr(char *string)
{
	if (string[0] == 45)
		return (6); // flag TOKEN
	else if (string[0] == 34)
		return (7); // double quote TOKEN
	else if (string[0] == 39)
		return (8); // single quote TOKEN
	else if (string[0] > 32 && string[0] < 127
		&& is_whitespace(string[1]) == false && is_valid_operator(string) == 0){
		return (9); // command or argument TOKEN
		}else
		return (0);
}

int	is_valid_operator(char *string)
{
	// return a number that represents the type of token
	if (string[0] == 124 && is_whitespace(string[1]))
		return (1); // pipe TOKEN
	else if (string[0] == 62 && string[1] == 62 && is_whitespace(string[2]))
		return (2); // output redirection append TOKEN
	else if (string[0] == 60 && string[1] == 60)
		return (3); // input HEREDOC TOKEN
	else if (string[0] == 60 && is_whitespace(string[1]))
		return (4); // input redirection TOKEN
	else if (string[0] == 62 && is_whitespace(string[1]))
		return (5); // output redirection TOKEN
	else
		return (0);
}

void	token_type(int token)
{
	static int flag = 0;
	char	*tokens[] = {"TOKEN_END_INPUT", "TOKEN_PIPE",
			"TOKEN_REDIRECTION_APPEND", "TOKEN_HEREDOC", "TOKEN_REDIRECTION_IN",
			"TOKEN_REDIRECTION_OUT", "TOKEN_FLAG", "TOKEN_STRING_DOUBLE",
			"TOKEN_STRING_SINGLE", "TOKEN_COMMAND", "TOKEN_ARGUMENT"};
	if (token == 9)
	{
		printf("Token type: %s\n", tokens[token + flag]);//to be removed and changed with token assignment
		flag = 1;
		return;
	}else if (token == 1)
		flag = 0; 
	printf("Token type: %s\n", tokens[token]);
}

void	list_N_tokens(void);

void is_quote(char *string, int *i)
{
	while (token_smr(string + *i) != 7 && token_smr(string + *i) != 8)
	{
		(*i)++;
	}
}

void token_check_n_assignment(char *string, int *word_counter) {

    if (is_valid_operator(string) == 2 || is_valid_operator(string) == 3)
	{
        *word_counter = 2;
		return;
	}
	else
        *word_counter = 1;
    if (token_smr(string) == 7 || token_smr(string) == 8)
        is_quote(string, word_counter);
    while (is_valid_operator(string + *word_counter) == 0
           && is_whitespace(string[*word_counter]) == false)
    {
        (*word_counter)++;
    }
}

void	read_through_input(void)
{
	char	*input;
	char	*string;
	int		word_counter;

	input = "ls -la /home/user  |   echo \'Hello, World!\'   <<grep World";
	string = input;
	word_counter = 0;
	while (*string != '\0') // not accounting for structs and nodes yet
	{
		if (is_whitespace(*string))
		{
			string++;
			continue ;
			// jumps all whitespaces
		}
		token_type(is_valid_operator(string) + token_smr(string));
			// finds token type
		token_check_n_assignment(string, &word_counter);
		// ft_substr(string, words counter);
		string += word_counter;
	}
}

void	ft_lexer(void)
{
	printf("Lexer function\n");
	read_through_input();
}
