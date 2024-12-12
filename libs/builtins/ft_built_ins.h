#ifndef FT_BUILT_INS_H
# define FT_BUILT_INS_H
# include "../../inc/minishell.h"

typedef struct minishell_obj	t_minishell;

void	ft_echo(char	**args);
bool    ft_is_built_in(char *cmd, char **args, t_minishell *minishell);

#endif