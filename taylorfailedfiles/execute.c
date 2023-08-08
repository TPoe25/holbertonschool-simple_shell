#include "basic_shell.h"
#include <string.h>
#include <stdio.h>
/**
 * execute - execute a command and call the corresponding function
 * @args: an array of strings containing the command and its arguments
 * Return: on success, the return value of the executed command, or -1 if fail
 */
int execute(char **args)
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

	if (args == NULL || args[0] == NULL)
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
	fprintf(stderr, "command not found: %s\n", args[0]);
	return (-1);
}
