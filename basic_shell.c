#include "basic_shell.h"

/**
 * main - function to run shell to get output
 *
 * Return: Always 0 success
 **/
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		input_shell();
	}
	else
	{
		automated_shell();
	}
	return (0);
}
