/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:44:08 by jlievano          #+#    #+#             */
/*   Updated: 2024/11/08 19:49:35 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTOR_H
# define FT_EXECUTOR_H
# include "../../inc/minishell.h"

typedef struct minishell_obj	t_minishell;

void	ft_executor(t_minishell *minishell);
void	ft_execute_cmd(t_minishell *minishell);
t_dll	*ft_find_env(char *key, t_dll *env_list);
char	**ft_envs_to_array(t_dll *env_list);
char	*ft_strjoin3(char *str1, char *str2, char *str3);
char	*ft_find_cmd_path(char *cmd, t_dll *envs);
void	ft_print_envs(t_dll *env_list);

#endif
