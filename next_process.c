#include "basic_shell.h"

/**
 * next_process - searches and executes a command in directories
 * @args: an array of strings containing the command and its arguments
 * @directories: array of strings containing directories to search for the binary
 *
 * Return: On success, returns 0. On failure, returns -1.
 */
int next_process(char **args, char **directories)
{
    int i;
    char command[1024];
    struct stat st;
    pid_t pid;
    int report;

    for (i = 0; directories[i] != NULL; i++) {
        size_t cmd_len = strlen(directories[i]);
        size_t arg_len = strlen(args[0]);

        if (cmd_len + arg_len + 2 <= (size_t)sizeof(command)) {
            strcpy(command, directories[i]);
            command[cmd_len] = '/';
            strcpy(command + cmd_len + 1, args[0]);

            if (stat(command, &st) == 0 && st.st_mode & S_IXUSR) {
                pid = fork();
                if (pid == -1) {
                    perror("fork");
                    return -1;
                }

                if (pid == 0) {
                    execve(command, args, NULL);
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
                while (waitpid(pid, &report, WUNTRACED) == -1)
                    perror("waitpid");

                return WIFEXITED(report) ? WEXITSTATUS(report) : WTERMSIG(report);
            }
        }
    }
    fprintf(stderr, "%s: command not found\n", args[0]);
    return -1;
}

