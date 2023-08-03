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
int next_process(char **args, char **directories) {
    int report;
    char *command_path = find_command(args[0], directories);
    pid_t pid;
    pid = fork();

	if (strcmp(args[0], "cp") == 0) {
        if (args[1] == NULL || args[2] == NULL) {
            printf("Usage: cp <source_file> <destination_file>\n");
            return 0;
        }
        if (copy_file(args[1], args[2]) == 0) {
            printf("File copied successfully.\n");
        } else {
            printf("Failed to copy file.\n");
        }
        return 0;
    }
    if (command_path == NULL) {
        printf("Command not found: %s\n", args[0]);
        return 0;
    }
    if (pid == 0) {
        if (execve(command_path, args, environ) == -1) {
            perror("Error in next_process");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("forking: error in next_process");
    } else {
        do {
            waitpid(pid, &report, WUNTRACED);
        } while (!WIFEXITED(report) && !WIFSIGNALED(report)); 
    }
    return 0;
}
