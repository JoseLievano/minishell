/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipes_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:34:18 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/16 17:34:19 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static size_t	get_cmd_len(t_dll *tk_list)
{
	size_t	counter;
	t_dll	*head;
	size_t	len_list;
	size_t	i;

	head = t_dll_get_head(tk_list);
	i = 0;
	len_list = t_dll_size(head);
	counter = 0;
	while(i < (len_list -1))
	{
		head = t_dll_get_node_index(head, i);
		counter += (ft_strlen(((t_token *)head->content)->value) + 1);
		//printf("\nadding: %s: %d", ((t_token *)head->content)->value, (int)counter);
		i++;
	}
	return (counter);
}

static void	put_value_in_cmd(char *ft_cmd, size_t *i, t_dll *node)
{
	char	*value;
	int		tk_value_len;
	int		j;

	if (!ft_cmd)
		return ;
	value = ((t_token *)node->content)->value;
	printf("\nstart index: %d | node value : %s | actual str: %s", (int)(*i),value, ft_cmd);
	j = 0;
	tk_value_len = ft_strlen(value);
	while(j < tk_value_len)
	{
		ft_cmd[*i] = value[j];
		j++;
		(*i)++;
	}
	ft_cmd[*i] = ' ';
	(*i)++;
}

char	*ft_get_pipes_cmd(t_dll *tk_list)
{
	char	*ft_cmd;
	size_t	len;
	size_t	i;
	size_t	node_i;

	i = 0;
	node_i = 0;
	len = get_cmd_len(tk_list);
	ft_cmd = (char *)malloc(sizeof(char) * (len + 1));
	ft_bzero(ft_cmd, len + 1);
	while (i < len)
	{
		put_value_in_cmd(ft_cmd, &i, t_dll_get_node_index(tk_list, node_i));
		node_i++;
	}
	//printf("\nCMD: [%s]\n", ft_cmd);
	ft_cmd[i - 1] = '\0';
	printf("\nlen: %d| Cmd: [%s]\n",(int)ft_strlen(ft_cmd), ft_cmd);
	return ft_cmd;
}
