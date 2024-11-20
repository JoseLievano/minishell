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
	//char	*complete_path;
	char	*temp;

	temp = NULL;
	//complete_path = NULL;
	while (*dirs)
	{
		temp = ft_strjoin3(*dirs, "/", cmd);
		printf("\nChecking: [%s]", temp);
		if (access(temp, F_OK | X_OK) == 0)
			printf("\nfound in %s\n", temp);
		free(temp);
		dirs++;
	}
	return (NULL);
}

char	*ft_find_cmd_path(char *cmd, t_dll *envs)
{
	char	**paths;
	t_dll	*path_node;

	printf("\nft_find_cmd_path cmd : %s", cmd);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_node = ft_find_env("PATH", envs);
	//printf("\nPath value: \n%s\n\n\n", ((t_env *) path_node->content)->value);
	paths = ft_split(((t_env *)path_node->content)->value, ':');
	char *valid_path = find_valid_path(paths, cmd);
	if (valid_path)
		printf("path valid");
	else
		printf("path not valid");
	/*
	printf("\ngot paths");
	while (*paths)
	{
		printf("\n%s", *paths);
		paths++;
	}
	*/
	return (((t_env *)path_node->content)->key);
}