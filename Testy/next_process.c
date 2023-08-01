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
	char *full_path = search_path(args);

	if (full_path)
	{
	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("error in next_process");
		}
		free(full_path);
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
	else 
	{
	fprintf(stderr, "./hsh :1 %s: not found \n", args[0]);
	return (127);
	}

