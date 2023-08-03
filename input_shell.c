#include "basic_shell.h"

/**
 * input_shell - shell process that receives input to line and prints output
 * @directories: array of strings containing directories to search for the binary
 *
 * Return: void
 **/
void input_shell(char **directories)
{
    char *line;
    char **args;
    int report = -1;
    int i;

    do {
        printf("Basic_$hell: ");
        line = read_line_stream();
        args = parse_string(line);
        report = execute(args, directories);

        free(line);

        for (i = 0; args[i] != NULL; i++) {
            free(args[i]); /* Free the individual tokens */
        }

        free(args);

        if (report >= 0)
        {
            exit(report);
        }
    } while (report == -1);
}
