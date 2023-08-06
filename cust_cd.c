#include "basic_shell.h"

/**
 * cust_cd - changing working directory of the current shell environment
 * @args: the target directory
 * Return: 1 if successful, 0 otherwise.
 **/

int cust_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "error to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error while changing directory\n");
		}
	}
	return (1);
}
