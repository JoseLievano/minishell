/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:01:29 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/21 20:01:30 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

static char *get_current_name(int i, char *shell_dir)
{
	char	*name;
	char	*number;

	number = ft_itoa(i);
	if (!number)
		return (NULL);
	name = ft_strjoin3(shell_dir, ".heredoc_minishell_", number);
	if (!name)
	{
		free(number);
		return (NULL);
	}
	free(number);
	return (name);
}

static char	*get_heredoc_file_name(t_minishell *minishell)
{
	char	*heredoc_name;
	int		i;
	int		fd;

	i = 0;
	while (1)
	{
		heredoc_name = get_current_name(i, minishell->shell_dir);
		if (!heredoc_name)
			return (NULL);
		fd = open(heredoc_name, O_RDONLY);
		if (fd == -1)
			break ;
		free(heredoc_name);
		heredoc_name = NULL;
		close(fd);
		i++;
	}
	return (heredoc_name);
}

static void	write_on_heredoc(t_redir *redirection)
{
	char	*line;
	char	*del;

	line = NULL;
	del= redirection->delimiter;
	while (true)
	{
		line = readline("> ");
		if (!line || (ft_strlen(del) == ft_strlen(line)))
			if (ft_strncmp(line, del, ft_strlen(del)) == 0)
			{
				free(line);
				break ;
			}
		write(redirection->fd, line, ft_strlen(line));
		write(redirection->fd, "\n", 1);
		free(line);
	}
}

bool	ft_process_heredoc(t_redir *redirection, t_minishell *minishell)
{
	char	*heredoc_file;

	heredoc_file = get_heredoc_file_name(minishell);
	if (!heredoc_file)
	{
		minishell->last_output = 1;
		return (false);
	}
	redirection->fd = open(heredoc_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (redirection->fd == -1)
	{
		minishell->last_output = 1;
		free(heredoc_file);
		return (false);
	}
	write_on_heredoc(redirection);
	unlink(heredoc_file);
	free(heredoc_file);
	return (true);
}