#include "basic_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * execute_process - executes commands for new process
 * @command: commands passed
 * @args: arguments passed
 * @envList: array of strings containing the environment variables
 * Return: -1 for next
 **/
int execute_process(char *command, char **args, char **envList)
{
	pid_t pid = fork();
	int report;
	char **argList = malloc(2 * sizeof(char *));

	if (!argList)
	{
		perror("malloc");
		return (-1); }
	if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		argList[0] = args[0];
		argList[1] = NULL;

		if (execve(command, argList, envList) == -1)
		{
			perror("execve");
			free(argList);
			return (-1);
		}
		free(argList);
	}
	else
	{
		waitpid(pid, &report, 0);
		return (report);
	}
	return (-1);
}
