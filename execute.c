#include "basic_shell.h"
/**
 *
 *
 *
*/
int execute(char **args)
{
	int b = 0;

	char *builtin_func_list[] =
	{
		"cd",
		"env",
		"exit",
		"help"
	};
	int (*builtins[])(char **) =
	{
		&own_cd,
		&own_env,
		&own_help,
		&own_exit,
	};
	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; b < sizeof(builtin_func_list[b]) == 0)
	{
		if (strcmp(args[0], builtin_func_list[b]) == 0)
		{
		return ((*builtins[b])(args));
		}
	}
	return (next_process(args));

}
