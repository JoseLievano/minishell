#include "ft_lexer.h"

void	read_through_list(t_dll *list)
{
	t_dll	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("Token type: %s\n", ((t_token *)tmp->content)->type);
		printf("Token value: %s\n-\n", ((t_token *)tmp->content)->value);
		tmp = tmp->next;
	}
}

bool	is_whitespace(char c)
{
	if (c == 32 || c == 9 || c == 10 || c == 11 || c == 12 || c == 13
		|| c == '\0')
		return (true);
	return (false);
}

void	is_quote(char *string, int *i)
{
	while (token_smr(string + *i) != 7 && token_smr(string + *i) != 8)
	{
		(*i)++;
	}
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
		&& is_valid_operator(string) == 0)
	{
		return (9); // command or argument TOKEN
	}
	else
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
