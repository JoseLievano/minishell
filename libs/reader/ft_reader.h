/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:28:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/28 00:32:38 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READER_H
# define FT_READER_H
# include "../../inc/minishell.h"

typedef enum  token_type
{
	TOKEN_END_INPUT,
	TOKEN_PIPE,
	TOKEN_REDIRECTION_APPEND,
	TOKEN_TOKEN_HEREDOC,
	TOKEN_REDIRECTION_IN,
	TOKEN_REDIRECTION_OUT,
	TOKEN_FLAG,
	TOKEN_STRING_DOUBLE,
	TOKEN_STRING_SINGLE,
	TOKEN_COMMAND,
	TOKEN_ARGUMENT
}	t_token_type;

char	*ft_reader(void);

#endif
