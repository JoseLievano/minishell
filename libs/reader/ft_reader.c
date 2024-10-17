/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:41:04 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/17 17:34:31 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"
/*
static int	single_quotes_closed(char *prompt)
{
	printf("checking prompt %s", prompt);
	return false;
}
*/

static int	quotes_closed(char *prompt)
{
	int		i;
	int		open_quotes;
	int		inside_single_quotes;
	char	ac_char;

	i = 0;
	open_quotes = 0;
	inside_single_quotes = 0;
	//printf("\nChecking prompt \n[%s]\n", prompt);
	while (i < (int) ft_strlen(prompt))
	{
		ac_char = prompt[i];
		if (inside_single_quotes == 0 && ac_char == '"' && open_quotes == 0)
			open_quotes = 1;
		else if (ac_char == '"' && open_quotes == 1)
			open_quotes = 0;
		if (open_quotes == 0 && ac_char == '\'' && inside_single_quotes == 0)
			inside_single_quotes = 1;
		else if (ac_char == '\'' && inside_single_quotes == 1)
			inside_single_quotes = 0;
		i++;
	}
	//printf("==>%d-%d\n", open_quotes, inside_single_quotes);
	return (open_quotes + inside_single_quotes);
}

static bool	invalid_prompt(char *prompt)
{
	return (quotes_closed(prompt));
}

char	*ft_reader(void)
{
	char	*prompt;
	char	*temp_str1;
	char	*temp_str2;

	prompt = NULL;
	temp_str1 = NULL;
	temp_str2 = NULL;
	prompt = readline("minishell>$ ");
	while (invalid_prompt(prompt))
	{
		temp_str1 = readline("minishell>$ ");
		temp_str2 = prompt;
		prompt = ft_strjoin(prompt, temp_str1);
		free(temp_str1);
		free(temp_str2);
		temp_str1 = NULL;
		temp_str2 = NULL;
		//printf("\nNew prompt is: %s\n", prompt);
	}
	printf("\n we have a valid prompt : %s\n", prompt);
	add_history(prompt);
	return (prompt);
}
