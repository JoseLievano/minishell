#include "ft_built_ins.h"

void	ft_cd(char **args, t_minishell *minishell);

bool	ft_is_built_in(char *cmd, char **args, t_minishell *minishell)
{
	(void)minishell;
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
	{
		ft_echo(args);
		return (true);
	}
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
	{
		ft_cd(args, minishell);
		return (true);
	}
	return (false);
}
