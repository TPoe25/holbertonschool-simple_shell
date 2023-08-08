#include "basic_shell.h"

/**
 * next_process - starts new process
 * @args: array of strings to be passed
 * Return: -1 if success
 **/
int next_process(char **args)
{
    char *path_env = getenv("PATH");
    char *path_env_copy = strdup(path_env);
    char *directory = strtok(path_env_copy, ":");
    int result = -1;

    if (!path_env_copy)
    {
        perror("strdup");
        return -1;
    }

    while (directory)
    {
        char command[1024];
        snprintf(command, sizeof(command), "%s/%s", directory, args[0]);

        if (access(command, X_OK) == 0)
        {
            result = execute_process(command, args, environ);
            break;
        }

        directory = strtok(NULL, ":");
    }

    free(path_env_copy);

    if (result == -1)
    {
        fprintf(stderr, "Command not found: %s\n", args[0]);
    }

    return (result);
}
