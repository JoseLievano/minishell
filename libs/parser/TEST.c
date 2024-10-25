#include "ft_parser.h"

static t_cmdt *test1(void)
{
	t_cmdt	*command_table = (t_cmdt *)malloc(sizeof(t_cmdt));

	command_table->type = COMMAND;

	t_cmd *command = (t_cmd *)malloc(sizeof(t_cmd));
	command->name = ft_strdup("echo");

	t_arg *argument1 = (t_arg *)malloc(sizeof(t_arg));
	argument1->type = STRING_DOUBLE;
	argument1->value = (char *)ft_strdup("Hello there $USER");

	t_dll *args = NULL;
	t_dll_add_front(&args, t_dll_new(argument1));

	command->arguments = args;
	command->flags = NULL;
	command->redirections = NULL;

	command_table->content = command;

	return command_table;
}

t_cmdt	*get_test(int test_num)
{
	if (test_num == 1)
		return test1();
	return NULL;
}
