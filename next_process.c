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

	pid = fork(); /* create a new process */
	if (pid == 0)
	{
	/* child process, execute the specified command */
		if (execvp(args[0], args) == -1)
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
	/* parent process, wait for the child process to complete */
		do

		{
	/* wait for the child process to change states */
			waitpid(pid, &report, WUNTRACED);
		}	while (!WIFEXITED(report) && !WIFSIGNALED(report));
	}
	return (-1);
}
