#include "basic_shell.h"

/**
 * main - main function
 *
 * Return: always 0 success
 **/

int main(void)
{
	char *directories[] = {"/bin", "/usr/bin", "./bin", NULL};

	if (isatty(STDIN_FILENO) == 1)
	{
		input_shell(directories);
	}
	else
	{
		automatedshell(directories);
	}
	return (0);
}
