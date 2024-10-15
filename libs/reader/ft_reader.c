/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:28:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/15 11:10:17 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"

static bool	single_quotes_closed(char *prompt)
{
	printf("checking prompt %s", prompt);
	return false;
}

static bool	double_quotes_closed(char *prompt)
{
	printf("checking prompt %s", prompt);
	return false;
}

static bool	valid_prompt(char *prompt)
{
	return (double_quotes_closed(prompt) && single_quotes_closed(prompt));
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
	while (!valid_prompt(prompt))
	{
		temp_str1 = readline("minishell>$ ");
		temp_str2 = prompt;
		prompt = ft_strjoin(prompt, temp_str1);
		free(temp_str1);
		free(temp_str2);
		temp_str1 = NULL;
		temp_str2 = NULL;
		printf("\nNew prompt is: %s\n", prompt);
	}
	add_history(prompt);
	return (prompt);
}
