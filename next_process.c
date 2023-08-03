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

    pid = fork();
    if (pid == 0)
    {
        char *full_path = find_command(args[0], directories);
        if (full_path == NULL)
        {
            fprintf(stderr, "Command not found: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }

        if (execv(full_path, args) == -1)
        {
            perror("Error in next_process");
        }
        free(full_path); /* Free allocated memory for full_path */
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Forking: Error in next_process");
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
