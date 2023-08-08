#include "basic_shell.h"
/**
 * main - basic shell
 * Return: 0 if success
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
