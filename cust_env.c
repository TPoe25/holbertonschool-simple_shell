#include "basic_shell.h"
#include <stdio.h>

/**
 * cust_env - custom command that prints environmental variables
 * @args: array of strings containing command and its arguments
 * Return: Always return -1
 */
int cust_env(char **args)
{
	{
		int i = 0; /* Declare and initialize the variable i in a separate block */

		(void)args; /* Cast args to void to indicate it is unused */

		while (environ[i])
		{
			/* Write each environment variable to the STDOUT */
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			/* Write a newline character to separate each environment variable */
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	return (-1);
}
