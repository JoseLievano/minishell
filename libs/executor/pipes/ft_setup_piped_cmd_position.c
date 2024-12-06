/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_piped_cmd_position.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 05:10:45 by jlievano          #+#    #+#             */
/*   Updated: 2024/12/06 05:10:47 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static void set_single_element_position(t_dll *current)
{
	((t_piped_cmd *)current->content)->position = PIPE_START;
}

static void set_two_elements_position(t_dll *current)
{
	((t_piped_cmd *)current->content)->position = PIPE_START;
	current = current->next;
	((t_piped_cmd *)current->content)->position = PIPE_END;
}

static void set_multiple_elements_position(t_dll *current, size_t size)
{
	size_t i = 0;
	while (current)
	{
		if (i == 0)
			((t_piped_cmd *)current->content)->position = PIPE_START;
		else if (i == size - 1)
			((t_piped_cmd *)current->content)->position = PIPE_END;
		else
			((t_piped_cmd *)current->content)->position = PIPE_MIDDLE;
		current = current->next;
		i++;
	}
}

void ft_setup_piped_cmd_position(t_dll *piped_cmd)
{
	if (!piped_cmd)
		return;

	size_t size = t_dll_size(piped_cmd);
	t_dll *current = t_dll_get_head(piped_cmd);

	if (size == 1)
		set_single_element_position(current);
	else if (size == 2)
		set_two_elements_position(current);
	else
		set_multiple_elements_position(current, size);
}
