/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:28:59 by jlievano          #+#    #+#             */
/*   Updated: 2024/10/28 15:26:22 by glicciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READER_H
# define FT_READER_H
# include "../../inc/minishell.h"

char	*ft_reader(void);
char	*set_prompt(char *current_prompt, char *new_input);
void	handle_eof(char *prompt, char *new_input);

#endif
