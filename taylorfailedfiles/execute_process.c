#include "basic_shell.h"
/**
 * execute_process - executes commands for a new process
 * @command: The full path of the command to execute
 * @args: arguments passed to command
 * @envList: array of strings containing the environment variables
 * Return: -1 for next
 **/
int execute_process(char *command, char **args, char **envList)
{
	pid_t pid = fork();
	int report, i;
	int num_args = 0;
	char **argList = NULL;

	if (pid < 0)
	{
		perror("fork");
		return (-1); }
	else if (pid == 0)
	{
		while (args[num_args])
			num_args++;
		argList = malloc((num_args + 1) * sizeof(char *));
		if (!argList)
		{
			perror("malloc");
			return (-1);
		}
		for (i = 0; i < num_args; i++)
		{
			argList[i] = args[i]; }
		argList[num_args] = NULL;

		if (execve(command, argList, envList) == -1)
		{
			perror("execve");
			free(argList);
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &report, 0);
		free(argList);
		return (report); }
	return (-1);
}

