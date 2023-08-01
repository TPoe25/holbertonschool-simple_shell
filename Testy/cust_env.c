#include "basic_shell.h"
/**
 * cust_env - custom command that prints environmental varaibles
 * @args: array of strings containing command and its arguments
 * Return: Always return -1
*/
int cust_env(char **args)
{
	int i = 0;
	(void)(**args); /* unused variable */

	while (environ[i])
	{
		/* write eache environ varuable to the STDOUT */
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		/* write a newline character to separate each environ variable */
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
