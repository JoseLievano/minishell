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

void	set_prompt(char *prompt, char *temp_str1, char *temp_str2)
{
	temp_str2 = prompt;
	prompt = ft_strjoin(prompt, temp_str1);
	free(temp_str1);
	free(temp_str2);
	temp_str1 = NULL;
	temp_str2 = NULL;
}
