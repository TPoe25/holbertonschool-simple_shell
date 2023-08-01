#include "basic_shell.h"
/**
 *next_process - creates a new process and executes the givven command
 *@args: array of strings containing the command and its arguments
 *Return: 1 on successful execution, 0 otherwise
*/
int next_process(char **args)
{
	pid_t pid;
	int report;

	pid = fork();
	if (pid == 0)
	{
		if (access(args[0], X_OK) == 0)
		{
		if (execvp(args[0], args) == -1)
		{
			perror("error in next_process");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		exit(127);
	}
	}
	else if (pid < 0)
	{
		perror("forking: error in next_process");
	}
	else
	{
		do

		{
			waitpid(pid, &report, WUNTRACED);
		}	while (!WIFEXITED(report) && !WIFSIGNALED(report));
	}
	return (-1);
}
