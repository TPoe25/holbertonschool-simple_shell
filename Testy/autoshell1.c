#include "basic_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * automatedshell - non-interactive shell unix command line interpreter
 * @command: the command to execute (NULL-terminated array of strings)
 *
 * Return: void
 */
void automatedshell(char **command)
{
    char *line = NULL;
    char **args;
    int report = -1;
    char *default_path = "/usr/local/bin:/usr/bin:/bin:./bin";
    (void)command;


    /* Set the PATH variable to include standard directories
     * separated by colons (:) for Linux/macOS or semicolons (;) for Windows.
     * Add ./bin as the last element */
    setenv("PATH", default_path, 1);

    do {
        printf("Basic_$hell: ");
        line = read_line_stream();
        args = parse_string(line);
        report = execute(args);

        free(line);
        free(args);

        if (report >= 0) {
            exit(report);
        }
    } while (report == -1);
}

