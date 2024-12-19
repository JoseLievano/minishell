#include "ft_lexer.h"

void	read_through_list(t_dll *list)
{
	t_dll	*tmp;
	char	*tokens[] = {"TOKEN_END_INPUT", "TOKEN_PIPE",
			"TOKEN_REDIRECTION_APPEND", "TOKEN_HEREDOC", "TOKEN_REDIRECTION_IN",
			"TOKEN_REDIRECTION_OUT", "TOKEN_FLAG", "TOKEN_ARGUMENT",
			"TOKEN_COMMAND"};

	tmp = list;
	while (tmp)
	{
		printf("Token type: %s\n", tokens[((t_token *)tmp->content)->type]);
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

t_token_type	token_smr(char *string)
{
	if (string[0] == 45)
		return (6);
	else if (string[0] > 32 && string[0] < 127
		&& is_valid_operator(string) == 0)
	{
		return (7);
	}
	else
		return (0);
}

t_token_type	is_valid_operator(char *string)
{
	if (string[0] == 124)
		return (1);
	else if (string[0] == 62 && string[1] == 62)
		return (2);
	else if (string[0] == 60 && string[1] == 60)
		return (3);
	else if (string[0] == 60)
		return (4);
	else if (string[0] == 62)
		return (5);
	else
		return (0);
}
