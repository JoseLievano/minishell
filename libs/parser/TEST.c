#include "ft_parser.h"

static t_cmdt *test1(void)
{
	// t_cmdt for command: echo "Hello $USER"

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

static t_cmdt *test2(void)
{
	// t_cmdt for command: echo "Hello $USER" > file.txt
	t_cmdt	*command_table = (t_cmdt *)malloc(sizeof(t_cmdt));
	command_table->type = COMMAND;
	t_cmd *command = (t_cmd *)malloc(sizeof(t_cmd));
	command->name = ft_strdup("echo");
	t_arg *argument1 = (t_arg *)malloc(sizeof(t_arg));
	argument1->type = STRING_DOUBLE;
	argument1->value = (char *)ft_strdup("Hello $USER");
	t_dll *args = NULL;
	t_dll_add_front(&args, t_dll_new(argument1));
	command->arguments = args;
	command->flags = NULL;
	t_redir *redir = (t_redir *)malloc(sizeof(t_redir));
	redir->type = REDIR_OUTPUT;
	redir->delimiter = NULL;
	redir->file_path = ft_strdup("file.txt");
	t_dll *redirections = NULL;
	t_dll_add_front(&redirections, t_dll_new(redir));
	command->redirections = redirections;
	command_table->content = command;
	return command_table;
}

static t_cmdt *test3(void)
{
	// t_cmdt for command: echo "Hello $USER" > file.txt | grep "Hello" | wc -l
	t_cmdt	*command_table = (t_cmdt *)malloc(sizeof(t_cmdt));
	command_table->type = PIPE_SEQ;
	t_pipes *pipes = (t_pipes *)malloc(sizeof(t_pipes));
	pipes->cmd_count = 0;
	t_dll *cmds = NULL;
	t_cmd *command1 = (t_cmd *)malloc(sizeof(t_cmd));
	command1->name = ft_strdup("echo");
	t_arg *argument1 = (t_arg *)malloc(sizeof(t_arg));
	argument1->type = STRING_DOUBLE;
	argument1->value = (char *)ft_strdup("Hello $USER");
	t_dll *args = NULL;
	t_dll_add_front(&args, t_dll_new(argument1));
	command1->arguments = args;
	command1->flags = NULL;
	t_redir *redir = (t_redir *)malloc(sizeof(t_redir));
	redir->type = REDIR_OUTPUT;
	redir->delimiter = NULL;
	redir->file_path = ft_strdup("file.txt");
	t_dll *redirections = NULL;
	t_dll_add_front(&redirections, t_dll_new(redir));
	command1->redirections = redirections;
	t_cmd *command2 = (t_cmd *)malloc(sizeof(t_cmd));
	command2->name = ft_strdup("grep");
	t_arg *argument2 = (t_arg *)malloc(sizeof(t_arg));
	argument2->type = STRING_DOUBLE;
	argument2->value = (char *)ft_strdup("Hello");
	t_dll *args2 = NULL;
	t_dll_add_front(&args2, t_dll_new(argument2));
	command2->arguments = args2;
	command2->flags = NULL;
	command2->redirections = NULL;
	t_cmd *command3 = (t_cmd *)malloc(sizeof(t_cmd));
	command3->name = ft_strdup("wc");
	command3->arguments = NULL;
	t_dll *flags = NULL;
	t_dll_add_front(&flags, t_dll_new(ft_strdup("-l")));
	command3->flags = flags;
	command3->redirections = NULL;
	t_dll_add_front(&cmds, t_dll_new(command1));
	t_dll_add_back(&cmds, t_dll_new(command2));
	t_dll_add_back(&cmds, t_dll_new(command3));
	pipes->cmds = cmds;
	pipes->cmd_count = (int)t_dll_size(cmds);
	command_table->content = pipes;
	return command_table;
}

t_cmdt	*get_test(int test_num)
{
	if (test_num == 1)
		return test1();
	if (test_num == 2)
		return test2();
	if (test_num == 3)
		return test3();
	return NULL;
}
