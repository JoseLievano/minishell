/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glicciar <glicciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:13:23 by glicciar          #+#    #+#             */
/*   Updated: 2024/11/06 22:14:34 by glicciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPANDER_H
# define FT_EXPANDER_H
# include "../../inc/minishell.h"

typedef struct minishell_obj	t_minishell;

void	ft_expander(t_minishell *minishell);
int		count_env(char *str);
char	*get_word(char *str);
char	**get_envs(char *str, t_dll *envs);
char	*ft_strjoin_char(char *str, char c);
char	*expanding(char *str, t_dll *envs, int last);
char	*quotes_breakdown_n_expantion(char *str, t_dll *envs, int last_output);

#endif