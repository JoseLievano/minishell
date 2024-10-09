/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:17:04 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/06 14:17:05 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READER_H
# define FT_READER_H
# include "../../inc/minishell.h"

typedef struct test
{
    char    *token_type;
    int     value;
} t_test;

void	ft_reader_test(void);
#endif
