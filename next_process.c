#include "basic_shell.h"

/**
 * next_process - creates a new process and executes give command
 * @args: array of strings containing comand and its args
 * Return: 1 on success, 0 otherwise
 **/

int next_process(char **args)
{
	pid_t pid;
	int report;

	pid = fork();
	if (pid == 0)
	{
		char *env[] = {NULL};
		if (execve(args[0], args, env) == -1)
		{
			perror("error in next_process");
		}
		exit(EXIT_FAILURE);
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
		} while (!WIFEXITED(report) && !WIFSIGNALED(report));
	}
	return (-1);
}
