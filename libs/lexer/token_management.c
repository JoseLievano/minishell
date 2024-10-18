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
	token->type = NULL;
	token->value = NULL;
	return (token);
}

void	list_tokens(t_dll **list, t_token *token)
{
	//t_dll_new(token);
	t_dll_add_back(list, t_dll_new(token));
};


void	token_type(int token_kind, t_token *token, t_dll **list)
{
	static int	flag = 0;
	char		*tokens[] = {"TOKEN_END_INPUT", "TOKEN_PIPE",
				"TOKEN_REDIRECTION_APPEND", "TOKEN_HEREDOC",
				"TOKEN_REDIRECTION_IN", "TOKEN_REDIRECTION_OUT", "TOKEN_FLAG",
				"TOKEN_STRING_DOUBLE", "TOKEN_STRING_SINGLE", "TOKEN_COMMAND",
				"TOKEN_ARGUMENT"};

	if (token_kind == 9)
	{
		token->type = tokens[token_kind + flag];
		// printf("Token type: %s\n", tokens[token_kind
		//	+ flag]);//to be removed and changed with token assignment
		flag = 1;
		list_tokens(list, token);
		return ;
	}
	else if (token_kind == 1)
		flag = 0;
	// printf("Token type: %s\n", tokens[token_kind]);
	token->type = tokens[token_kind];
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
		*word_counter = 1;
	if (token_smr(string) == 7 || token_smr(string) == 8)
		is_quote(string, word_counter);
	while (is_valid_operator(string + *word_counter) == 0
		&& is_whitespace(string[*word_counter]) == false)
	{
		(*word_counter)++;
	}
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
