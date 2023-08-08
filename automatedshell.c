#include "basic_shell.h"

/**
 * automatedshell - non interactive shell unix command line interepeter
 *
 * Return: void
 **/

void automatedshell(void)
{
	char *line;
	char **args;
	int report = -1;

	do {
		line = read_line_stream(); /*reads a line from the input str */
		args = parse_string(line);/*parses the line and extracts argu*/
		report = execute(args);/*executes command specified by argum */

		free(line); /* frees memory allocated for input line*/
		free(args); /* frees memory for parsed arguments */
	/* checks if command executed returned a non negative value */
		if (report >= 0)
		{
			exit(report);
		}
	}
	/* cont. looping until a non neg value is returned */

		while
		(report == -1);
}
