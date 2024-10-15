/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:28:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/13 20:11:35 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"

char	*ft_reader(void)
{
	char	*str;

	printf("Starting ft_reader");
	str = readline("minishell> ");
	add_history(str);
	printf("Your input was: \n%s\n", str);
	str = readline("minishell > ");
	printf("Your input was: \n%s\n", str);
	return (str);
}
