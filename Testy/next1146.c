#include "basic_shell.h"
/**
 * next_process - find and execute the next process in directories
 * @args: array of strings containing commands and args
 * @envList
 * Return: 0 on success, -1 on fail.
 **/
int next_process(char **args)
{
	char command[1024] = {0};
	struct stat st;
	char *path_env = NULL, *directories[1024], *path_env_copy = NULL;
	int i, dir_count = 0;
	char **environ_ptr = environ;

	if (args == NULL || args[0] == NULL)
	{
		fprintf(stderr, "Invalid input: args is NULL or args[0] is NULL\n");
		return (-1); }
	while (*environ_ptr && strncmp(*environ_ptr++, "PATH=", 5))
		;
	if (*environ_ptr)
		path_env = *environ_ptr + 5;
	if (!path_env)
	{
		fprintf(stderr, "Could not get PATH environment variable\n");
		return (-1); }
	path_env_copy = strdup(path_env);
	if (!path_env_copy)
	{
		perror("strdup");
		return (-1); }
	directories[dir_count++] = strtok(path_env_copy, ":");

	while ((path_env_copy = strtok(NULL, ":")))
	{
		directories[dir_count++] = path_env_copy; }
	free(path_env_copy);
	for (i = 0; i < dir_count; i++)
	{
		strcpy(command, directories[i]);
		strcat(strcat(command, "/"), args[0]);
		if (stat(command, &st) == 0 && st.st_mode & S_IXUSR)
		{
			return (execute_process(command, args)); } }
	fprintf(stderr, "Command not found: %s\n", args[0]);
	return (-1);
}
