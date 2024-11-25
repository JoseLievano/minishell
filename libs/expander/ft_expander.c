#include "ft_expander.h"

void run_through_arguments(t_cmd *command_table)
{
	t_dll *tmp;
	printf("\nCommand name: %s", command_table->name);
	tmp = command_table->arguments;
	while ((t_dll *)tmp)
	{
		printf("\nArgument: %s", ((t_arg *)tmp->content)->value);
		tmp = tmp->next;	
	}
	printf("\n");
}

void	ft_expander(t_minishell *minishell)
{
	t_cmdt *command_table = minishell->cmdt;
	if (command_table->type == PIPE_SEQ)
		return ;
	run_through_arguments(command_table->content);



	//t_dll *path_node = ft_find_env("PATH", minishell->envs);
	//t_env *result_env = (t_env *)path_node->content;
	//printf("\nPath value: %s", result_env->value);
}