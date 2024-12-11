#ifndef FT_BUILT_INS_H
# define FT_BUILT_INS_H
# include "../../inc/minishell.h"

void	ft_built_ins(char	**args);
bool    ft_is_built_in(char *cmd, char **args, char **envs);

#endif