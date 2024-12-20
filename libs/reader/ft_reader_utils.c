/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:43:16 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/19 23:43:17 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"

char	*set_prompt(char *current_prompt, char *new_input)
{
	char	*new_prompt;

	if (!new_input)
		return (NULL);
	new_prompt = ft_strjoin(current_prompt, new_input);
	free(current_prompt);
	free(new_input);
	return (new_prompt);
}

void	handle_eof(char *prompt, char *new_input)
{
	if (new_input)
		free(new_input);
	if (prompt)
		free(prompt);
}
