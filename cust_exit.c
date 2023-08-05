#include "basic_shell.h"

/**
 * cust_exit - terminates normal process
 * @args: empty arguments
 * Return: -two to indicate that the shell should not exit
 **/
int cust_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (-2); /* Return -two to indicate that the shell should not exit */
	}
}
