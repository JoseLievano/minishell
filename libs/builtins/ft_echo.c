/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabri <gabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:40 by gabri             #+#    #+#             */
/*   Updated: 2024/12/19 03:14:55 by gabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_ins.h"

bool	is_valid_flag(char *arg)
{
	int	j;

	j = 0;
	while (arg[j + 2] != '\0')
	{
		if (arg[(j++) + 2] == 'n')
			continue ;
		else
			return (false);
	}
	return (true);
}

int	flag_processing(char **args)
{
	int	i;

	i = 1;
	while (args[i] && ft_strncmp(args[i], "-n", 2) == 0)
	{
		if (ft_strlen(args[i]) > 2)
		{
			if (is_valid_flag(args[i]) == true)
			{
				i++;
				continue ;
			}
			break ;
		}
		i++;
	}
	return (i);
}

void	ft_echo(char **args)
{
	bool	flag;
	int		i;

	i = 1;
	if (flag_processing(args) > 1)
	{
		flag = true;
		i = flag_processing(args);
	}
	else
		flag = false;
	if (args[i])
	{
		printf("%s", args[i]);
		i++;
	}
	while (args[i])
	{
		printf(" ");
		printf("%s", args[i]);
		i++;
	}
	if (flag == false)
		printf("\n");
}
