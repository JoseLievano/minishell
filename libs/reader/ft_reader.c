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

static bool	empty_prompt(char *prompt)
{
	int	i;

	if (!prompt || ft_strlen(prompt) == 0)
		return (true);
	i = 0;
	while (prompt[i])
	{
		if (!is_whitespace(prompt[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	invalid_prompt(char *prompt)
{
	int	qoutes_status;
	int	pipe_status;

	qoutes_status = quotes_closed(prompt);
	pipe_status = not_pipe_ending(prompt);
	if (empty_prompt(prompt))
		return (1);
	return (qoutes_status + pipe_status);
}

char	*ft_reader(void)
{
	char	*prompt;
	char	*new_input;

	prompt = readline("minishell>$ ");
	if (ft_check_eof(prompt))
		return (NULL);
	while (invalid_prompt(prompt))
	{
		new_input = readline("minishell>$ ");
		if (ft_check_eof(new_input))
		{
			handle_eof(prompt, new_input);
			return (NULL);
		}
		prompt = set_prompt(prompt, new_input);
		if (!prompt)
			return (NULL);
	}
	if (prompt)
		add_history(prompt);
	return (prompt);
}
