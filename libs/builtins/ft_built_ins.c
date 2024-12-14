#include "ft_built_ins.h"

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
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
	{
		ft_pwd(minishell);
		return (true);
	}
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
	{
		ft_export(args, minishell);
		return (true);
	}
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
	{
		print_env(minishell->envs);
		return (true);
	}
	return (false);
}


