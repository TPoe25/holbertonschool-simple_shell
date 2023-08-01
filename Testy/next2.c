#include "basic_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * next_process - creates a new process and executes the given command
 * @args: array of strings containing the command and its arguments
 * Return: 1 on successful execution, 0 otherwise
 */
int next_process(char **args)
{
    pid_t pid;
    int report;

    pid = fork();
    if (pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror("error in next_process");
        }
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

