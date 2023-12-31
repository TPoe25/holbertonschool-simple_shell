#include "basic_shell.h"

/**
 * main - main function
 *
 * Return: always 0 success
 **/

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		input_shell(); /* run the shell in interactive mode */
	}
	else
	{
		automatedshell(); /* run the shell in non interactive mode */
	}
	return (0);
}
