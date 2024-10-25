/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:41:04 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/25 17:23:29 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"

static int	not_pipe_ending(char *promt)
{
	int		i;

	i = ft_strlen(promt) - 1;
	while (is_whitespace(promt[i]))
		i--;
	if (promt[i] == '|')
		return (1);
	return (0);
}

static int	quotes_closed(char *prompt)
{
	int		i;
	int		open_quotes;
	int		inside_single_quotes;
	char	ac_char;

	i = 0;
	open_quotes = 0;
	inside_single_quotes = 0;
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
	return (open_quotes + inside_single_quotes);
}

static int invalid_prompt(char *prompt)
{
	int	qoutes_status;
	int	pipe_status;

	qoutes_status = quotes_closed(prompt);
	pipe_status = not_pipe_ending(prompt);
	return (qoutes_status + pipe_status);
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
	}
	//printf("\n> We have a valid prompt : \n[%s]\n\n", prompt);
	add_history(prompt);
	return (prompt);
}
