#include "basic_shell.h"

/**
 * cust_exit - exits the shell with a exit code
 * @args: the args passed to the cust_exit function
 * Return: The exit code specified in args[1] if present
 **/

int cust_exit(char **args)
{
	if (args[1])
	{
	/* if args[1] is not NULL, convert it to an integer */
		return (atoi(args[1]));
	}
	else
	{
	/* if args[1] is NULL, no exit code was provided */
		return (0);
	}
}
