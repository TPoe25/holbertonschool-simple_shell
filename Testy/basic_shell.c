#include "basic_shell.h"

/**
 * main - main function
 *
 * Return: always 0 success
 **/
int main(void)
{
	char *directories[] = {"/bin", "/usr/bin", "./bin", NULL};

	if (isatty(STDIN_FILENO))
	{
		input_shell(directories);
	}
	else
	{
		automated_shell(directories, 0);
	}
	return (0);
}
