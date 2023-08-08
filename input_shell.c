#include "basic_shell.h"

/**
 * input_shell - shell process that recieves input to line and prints output
 *
 * Return: void
 **/

void input_shell(void)
{
	char *line;
	char **args;
	int report = -1;

	do {
		printf("Basic_$hell: "); /* print the shell prompt */
		line = read_line_stream(); /* read line from input stream */
		args = parse_string(line); /* parse the line */
		report = execute(args); /* execute the command by the argu */

		/* free memory allocated */
		free(line);
		free(args);
	/* check if the executed command returned a non neg value */
		if (report >= 0)
		{
			exit(report);
		}
	} while (report == -1);
}
