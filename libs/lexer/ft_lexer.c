/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/04 17:20:10 by glicciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	is_closed_quote(char *string) // goated
{
	int i;
	int j;
	int counter;

	i = 0;
	j = 0;
	counter = 0;
	if (string[counter] == 34)
		i++;
	if (string[counter] == 39)
		j++;
	counter++;
	while (((is_whitespace(string[counter]) == false)
			&& is_valid_operator(&string[counter]) == 0) || ((i % 2 != 0) || (j
				% 2 != 0)))
	{
		if (string[counter] == 34 && (j % 2 == 0))
			i++;
		if (string[counter] == 39 && (i % 2 == 0))
			j++;
		counter++;
	}
	return (counter);
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
		current_token->value = ft_substr(string, 0, word_counter);
		string += word_counter;
	}
	token_type(0, allocate_token(), &list);
	token_type(42, NULL, &list);
	return (list);
}

void	ft_lexer(void)
{
	t_dll	*list;
	char	*input;

	printf("Lexer function:\n\n");
	input = ft_reader();
	list = read_through_input(input);
	free(input);
	read_through_list(list);
	// free_nodes(list);
}
