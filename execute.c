#include "basic_shell.h"
/**
 * execute - execute a command and call corresponding function
 * @args: an array of strings containing the command and its arguments
 * Return: on success, the return value of the executed. -1 if failure
*/
int execute(char **args)
{
	unsigned long int b;

	char *builtin_func_list[] = {
		"cd",
		"env",
		"exit",
		"help"
	};
	int (*builtins[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit,
	};
	if (args[0] == NULL)
	{
		return (-1);
	}
	for (b = 0; b < sizeof(builtin_func_list) / sizeof(char *); b++)
	{
		if (strcmp(args[0], builtin_func_list[b]) == 0)
		{
		return ((*builtins[b])(args));
		}
	}
	return (new_process(args));

}
