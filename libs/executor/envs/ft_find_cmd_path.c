/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cmd_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 00:34:56 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/20 00:34:57 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

char	*ft_strjoin3(char *str1, char *str2, char *str3)
{
	char	*temp;
	char	*new_str;

	temp = ft_strjoin(str1, str2);
	new_str = ft_strjoin(temp, str3);
	free(temp);
	return (new_str);
}

static char	*find_valid_path(char **dirs, char *cmd)
{
	char	*temp;

	temp = NULL;
	while (*dirs)
	{
		temp = ft_strjoin3(*dirs, "/", cmd);
		if (access(temp, F_OK | X_OK) == 0)
			return (temp);
		free(temp);
		dirs++;
	}
	return (NULL);
}

char	*ft_find_cmd_path(char *cmd, t_dll *envs)
{
	char	**paths;
	t_dll	*path_node;
	char	*path;

	path = NULL;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_node = ft_find_env("PATH", envs);
	paths = ft_split(((t_env *)path_node->content)->value, ':');
	path = find_valid_path(paths, cmd);
	ft_free_char_array(paths);
	return (path);
}