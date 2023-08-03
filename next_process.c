#include "basic_shell.h"

/**
 * next_process - starts a new process
 * args: arguments
 * directories: directories
 * Return: 0 successful 
 **/

int next_process(char **args, char **directories)
{
	char command[1024] = {0};
	int report;
	struct stat st;
	pid_t pid = fork();

	if (args[0][0] == '/' && access(args[0], X_OK) == 0)
		strcpy(command, args[0]);
	else
		while (*directories)
		{
			char path[1024] = {0};

			strcat(strcat(strcat(path, *directories). "/"), args[0]);

			if (stat(path, &st) == 0 && st.st_mode & S_IXUSR)
			{
				strcpy(command, path);
				break; }
			directories++; }
	if (!command[0])
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		return (-1); }
	if (pid < 0)
	{
		perror("fork");
		return (-1); }
	else if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			return (-1); } } else
	{
		waitpid(pid, &report, 0);

		return (report); }
	return (0); }
