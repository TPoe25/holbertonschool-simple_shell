#include "basic_shell.h"
/**
 *
 *
 *
*/
char *find_command(char *command)
{
	char *find_command = NULL;
	char *path_env = getenv("PATH");
	char *dir = strtok(path_env, ":");
	char *path_tok = strtok(path_env, ":");
	int len = strlen(path_tok) + strlen(command) + 2;

	if (path_env)
	{
		while (dir)
		{
			find_command = malloc(strlen(dir) + strlen(args[0]) + 2);
			if (find_command == NULL)
			{
				perror ("malloc failed");
				exit (EXIT_FAILURE);
			}
			snprintf(find_command, len, %s/%s, path_tok, command);
			if (access(find_command, X_OK) == 0)
				break;
			free(find_command == NULL;
				path_tok = strtok(NULL, ":");
			}
	}
			return (find_command);
}

		i
