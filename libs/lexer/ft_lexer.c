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


t_dll	**read_through_input(char *input)
{
	char	*string;
	int		word_counter;
	t_token	*current_token;
	t_dll	**list;

	string = input;
	word_counter = 0;
	list = allocate_dll();
	while (*string != '\0') // not accounting for structs and nodes yet
	{
		if (is_whitespace(*string))
		{
			string++;
			continue ; // jumps all whitespaces
		}
		current_token = allocate_token();
		token_type(is_valid_operator(string) + token_smr(string), current_token,
			list);
		token_check_n_assignment(string, &word_counter);
		current_token->value = ft_substr(string, 0, word_counter);
		string += word_counter;
	}
	token_type(0, allocate_token(), list);
	return (list);
}

void	ft_lexer(void)
{
	printf("Lexer function:\n\n");
	read_through_list(read_through_input("grep \"error\" < log.txt | echo >> errors.txt"));
}
