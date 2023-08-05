#include "basic_shell.h"
/**
 * next_process - find and execute the next process in directories
 * @args: array of strings containing command and its arguments
 * @directories: array of strings containing directories to search for the binary
 * Return: 0 if successful, -1 on failure
 */
int next_process(char **args, char **directories)
{
	char command[1024] = {0};
	struct stat st;
	pid_t pid;

	if (directories == NULL)
	{
		fprintf(stderr, "Invalid input: directories is NULL\n");
		return (-1); }
	if (args == NULL || args[0] == NULL)
	{
		fprintf(stderr, "Invalid input: args is NULL or args[0] is NULL\n");
		return (-1); }
	if (args[0][0] == '/' && access(args[0], X_OK) == 0)
	{
		strcpy(command, args[0]); }
	else 
	{
		while (*directories)
		{
			strcpy(command, *directories);
			strcat(command, "/");
			strcat(command, args[0]);

			if (stat(command, &st) == 0 && st.st_mode & S_IXUSR)
			{
				break; }
			directories++; } }
	if (!command[0])
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		return (-1); }
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (-1); }
	else if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			return (-1); } }
	else
	{
		int report;
		waitpid(pid, &report, 0);
		return report; }
	return (0); }

