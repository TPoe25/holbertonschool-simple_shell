#include "basic_shell.h"
/**
 * execute - execute a command and call corresponding function
 * @args: an array of strings containing the command and its arguments
 * Return: on success, the return value of the executed. -1 if failure
*/
int execute(char **args)
{
	unsigned long int b;
	/* list of built-in comman names */
	char *builtin_func_list[] = {
		"cd",
		"env",
		"exit"
	};
	/* array of function pointers to the builtin functions */
	int (*builtins[])(char **) = {
		&cust_cd,
		&cust_env,
		&cust_exit
	};
	/* check if command is empty */
	if (args[0] == NULL)
	{
		return (-1);
	}
	/* iterate through builtin func to check if command matches */
	for (b = 0; b < sizeof(builtin_func_list) / sizeof(char *); b++)
	{
	/* compare the command name (args[0]) with each builtin name */
		if (strcmp(args[0], builtin_func_list[b]) == 0)
		{
	/* if match is found, call builtin func and return its return value */
		return ((*builtins[b])(args));
		}
	}
/* if not builtin , call next process */
	return (next_process(args));

}
