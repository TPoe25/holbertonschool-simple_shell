#include "basic_shell.h"

/**
 * main - main function
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments (unused)
 *
 * Return: always 0 success
 **/
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *directories[] = {"/bin", "/usr/bin", "./bin", NULL};

	if (argc > 1)
	{
		automatedshell(directories);
	}
	else if (isatty(STDIN_FILENO) == 1)
	{
		input_shell(directories);
	}
	else
	{
		automatedshell(directories);
	}
	return (0);
}
