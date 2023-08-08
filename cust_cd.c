#include "basic_shell.h"

/**
 * cust_cd - changing working directory of the current shell environment
 * @args: the target directory specified as an argument
 * Return: 1 if successful, 0 otherwise.
 **/

int cust_cd(char **args)
{
	if (args[1] == NULL)
	{
	/*if no target directory, display an error message */
		fprintf(stderr, "error to \"cd\"\n");
	}
	else
	{
		/*attempts change to the current working directory */
		if (chdir(args[1]) != 0)
		{
			perror("error while changing directory\n");
		}
	}
	return (0);
}
