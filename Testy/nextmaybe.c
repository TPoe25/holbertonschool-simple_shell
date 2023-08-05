#include "basic_shell.h"
/**
 * next_process - find and execute the next process in directories
 * @args: array of strings containing command and its arguments
 * Return: 0 if successful, -1 on failure
 **/
int next_process(char **args)
{
	char command[1024] = {0};
	struct stat st;
	char *path_env = NULL, *path_token, *directories[1024], *path_env_copy = NULL;
	int i, dir_count = 0;
	char **environ_ptr = environ;

	if (args == NULL || args[0] == NULL)
	{
		fprintf(stderr, "Invalid input: args is NULL or args[0] is NULL\n");
		return (-1); }
	while (*environ_ptr != NULL)
	{
		if (strncmp(*environ_ptr, "PATH=", 5) == 0)
		{
			path_env = *environ_ptr + 5;
			break; }
		environ_ptr++; }
	if (path_env == NULL)
	{
		fprintf(stderr, "Could not get PATH environment variable\n");
		return (-1); }
	path_env_copy = strdup(path_env);
	if (path_env_copy == NULL)
	{
		perror("strdup");
		return (-1); }
	path_token = strtok(path_env_copy, ":");
	while (path_token != NULL)
	{
		directories[dir_count++] = path_token;
		path_token = strtok(NULL, ":"); }
	free(path_env_copy);
	for (i = 0; i < dir_count; i++) {
		strcpy(command, directories[i]);
		strcat(command, "/");
		strcat(command, args[0]);
		if (stat(command, &st) == 0 && st.st_mode & S_IXUSR)
		{
			return (execute_process(command, args)); } }
	fprintf(stderr, "Command not found: %s\n", args[0]);
	return (-1); }
