#include "ft_built_ins.h"

bool	ft_is_built_in(char *cmd, char **args, t_minishell *minishell)
{
	(void)minishell;
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
	{
		ft_echo(args);
		return (true);
	}
	return (false);
}
