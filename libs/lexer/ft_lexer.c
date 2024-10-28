/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/28 17:38:07 by glicciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	check_variable(char *string, int *i, t_token *current_token)
{
	int	counter;
	int	counter2;

	counter = 0;
	counter2 = 0;
	if (current_token->type != 9 && current_token->type != 8)
		return ;
	while (token_smr(string + counter) != 7 && token_smr(string + counter) != 8
		&& is_whitespace(string[counter]) == false)
	{
		counter++;
	}
	if (token_smr(string + counter) == 7 || token_smr(string + counter) == 8)
	{
		counter2 = counter;
		is_quote(string + counter, &counter2);
		*i = counter + counter2 + 1;
	}
}

t_dll	*read_through_input(char *input)
{
	char	*string;
	int		word_counter;
	t_token	*current_token;
	t_dll	*list;

	string = input;
	word_counter = 0;
	list = NULL;
	while (*string != '\0') 
	{
		if (is_whitespace(*string))
		{
			string++;
			continue ; // jumps all whitespaces
		}
		current_token = allocate_token();
		token_type(is_valid_operator(string) + token_smr(string), current_token,
			&list);
		token_check_n_assignment(string, &word_counter);
		check_variable(string, &word_counter, current_token);
		current_token->value = ft_substr(string, 0, word_counter);
		string += word_counter;
	}
	token_type(0, allocate_token(), &list);
	return (list);
}

void	ft_lexer(void)
{
	t_dll	*list;
	char *input;
	printf("Lexer function:\n\n");
	input = ft_reader();
	list = read_through_input(input);
	free(input);
	read_through_list(list);
	//free_nodes(list);
}
