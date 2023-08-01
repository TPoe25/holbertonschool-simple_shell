#include "basic_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * next_process - creates a new process and executes the given command
 * @args: array of strings containing the command and its arguments
 * @directories: array of strings containing directories to search for the binary
 * Return: 1 on successful execution, 0 otherwise
 */
int next_process(char **args, char **directories)
{
    pid_t pid;
    int report;
    int i;

    pid = fork();
    if (pid == 0)
    {
        char *full_path = NULL;

        for (i = 0; directories[i] != NULL; i++)
        {
            full_path = malloc(strlen(directories[i]) + strlen(args[0]) + 2);
            if (full_path == NULL)
            {
                perror("malloc");
                exit(EXIT_FAILURE);
            }

            sprintf(full_path, "%s/%s", directories[i], args[0]);

            execve(full_path, args, environ);

            free(full_path);
        }

        perror("Command not found");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("forking: error in next_process");
    }
    else
    {
        do
        {
            waitpid(pid, &report, WUNTRACED);
        } while (!WIFEXITED(report) && !WIFSIGNALED(report));
    }
    return (-1);
}
