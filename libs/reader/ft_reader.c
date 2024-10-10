/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:17:09 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/07 14:50:16 by glicciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"

void	ft_reader()
{
	printf("Starting ft_reader");
	char *y_input = readline("minishell> ");
	add_history(y_input);
	printf("Your input was: \n%s\n", y_input);
	y_input = readline("minishell > ");
	printf("Your input was: \n%s\n", y_input);
}