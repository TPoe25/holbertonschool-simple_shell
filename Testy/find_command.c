#include "basic_shell.h"
/**
 *
 *
 *
*/
char *find_command(char *command)
{
	char *full_path = NULL;
	char *path = getenv("PATH");
	char *dir = strtok(path_env, ":");

	if (path)
	{
		while (dir)
		{
			full_path = malloc(strlen(dir) + strlen(args[0]) + 2);
			if (full_path == NULL)
			{
				perror("malloc failed");
				return (NULL);
			}
			sprintf(full_path, "%s/%s", dir, args[0]);
			if (access(full_path, X_OK) == 0)
			{
				return (full_path);
			}
			free(full_path);
			full_path = NULL;
			dir = strtok(NULL, ":");
			}
	}
			return (NULL);
}

		i
