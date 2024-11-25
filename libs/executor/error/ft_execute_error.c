/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:13:28 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/24 15:13:29 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_executor.h"

#include "../ft_executor.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void	ft_open_error(int errno)
{
	if (errno == EACCES)
		perror("Permission denied");
	else if (errno == EEXIST)
		perror("File exists");
	else if (errno == ENOENT)
		perror("No such file or directory");
	else if (errno == EISDIR)
		perror("Is a directory");
	else if (errno == EMFILE)
		perror("Too many open files");
	else if (errno == ENFILE)
		perror("Too many open files in system");
	else if (errno == EFBIG)
		perror("File too large");
	else if (errno == EROFS)
		perror("Read-only file system");
	else if (errno == EINVAL)
		perror("Invalid argument");
	else
		perror("Error opening file");
}
