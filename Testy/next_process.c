#include "basic_shell.h"
/**
 * next_process - starts new process
 * @args: array of strings to be passed
 * Return: -1 if success
 **/
int next_process(char **args)
{
	char command[1024] = {0};
	char *path_env = NULL, *directories[1024], *path_env_copy = NULL;
	int i, result, dir_count = 0;

	if (args == NULL || args[0] == NULL)
	{
		fprintf(stderr, "Invalid input: args is NULL or args[0] is NULL\n");
		free(path_env_copy);
		return (-1); }
	while (*environ && strncmp(*environ, "PATH=", 5))
		environ++;
	if (*environ)
		path_env = *environ + 5;
	if (!path_env)
	{
		fprintf(stderr, "Could not get PATH environment variable\n");
		free(path_env_copy);
		return (-1); }
	path_env_copy = strdup(path_env);
	if (!path_env_copy)
	{
		perror("strdup");
		free(path_env_copy);
		return (-1); }
	directories[dir_count++] = strtok(path_env_copy, ":");
	while ((path_env_copy = strtok(NULL, ":")))
	{
		directories[dir_count++] = path_env_copy; }
	for (i = 0; i < dir_count; i++)
	{
		snprintf(command, sizeof(command), "%s/%s", directories[i], args[0]);
		if (access(command, X_OK) == 0)
		{
			result = execute_process(command, args, environ);
			free(path_env_copy);
			return (result); } }
	fprintf(stderr, "Command not found: %s\n", args[0]);
	free(path_env_copy);
	return (-1); }
