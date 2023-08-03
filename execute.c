#include "basic_shell.h"
/**
 * execute - execute a command and call corresponding function
 * @args: an array of strings containing the command and its arguments
 * @directories: array of strings containing directories to search for the bin
 * Return: on success, the return value of the executed. -1 if failure
 */
int execute(char **args, char **directories)
{
	unsigned long int b;
	char *builtin_func_list[] = {
		"cd",
		"env",
		"exit"
	};
	int (*builtins[])(char **) = {
		&cust_cd,
		&cust_env,
		&cust_exit
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
	return (next_process(args, directories));
}
