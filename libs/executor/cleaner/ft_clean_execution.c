/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:14:20 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/13 15:14:21 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

void	ft_free_child_arrays(char **args, char **envs, char *cmd_path)
{
	if (envs)
		ft_free_char_array(envs);
	if (args)
		ft_free_char_array(args);
	if (cmd_path)
		free(cmd_path);
}
