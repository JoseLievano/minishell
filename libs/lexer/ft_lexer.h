/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:56:31 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/09 22:56:32 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H
# include "../../inc/minishell.h"

typedef struct s_token
{
    char           *type;
    char           *value;
} t_token;


void	ft_lexer(void);

# endif
