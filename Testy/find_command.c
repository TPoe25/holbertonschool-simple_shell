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
	char *path_tok = strtok(path_env, ":");
	int len = strlen(path_tok) + strlen(command) + 2;

	if (path_env != NULL)
	{
		while (path_tok != NULL)
		{
			find_command = malloc(len);
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

		
