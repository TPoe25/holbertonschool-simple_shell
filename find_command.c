#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * find_command - searches for the full path of a command in the specified directories
 * @command: the command to search for
 * @directories: array of strings containing directories to search for the command
 * Return: the full path of the command if found, NULL otherwise
 */
char *find_command(const char *command, char **directories)
{
	int i = 0, j = 0;
	size_t command_len = strlen(command);
	size_t k;

	while (directories[i] != NULL)
	{
		size_t dir_len = strlen(directories[i]);
		size_t path_len = dir_len + command_len + 2; /* +two for /'///'/ and null terminator */
	char *full_path = malloc(path_len);
	
	if (full_path == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	for (j = 0; j < (int)dir_len; j++)
		full_path[j] = directories[i][j];

	full_path[j++] = '/';
	for (k = 0; k < command_len; k++)
		full_path[j++] = command[k];

	full_path[j] = '\0';

	if (access(full_path, X_OK) == 0)
	{
		return full_path;
	}

	free(full_path);
		i++;
	}
	return NULL;
}
