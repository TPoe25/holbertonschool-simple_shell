#include "basic_shell.h"

/**
 * cust_exit - terminates normal process
 * @args: empty arguments
 * Return: 0 to terminate the current process
 **/

int cust_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}
