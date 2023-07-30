#include "basic_shell.h"

/**
 * automated_shell - non interactive shell unix command line interepeter
 *
 * Return: void
 **/

void automated_shell(void)
{
	char *line;
	char **args;
	int report = -1;

	do {
		line = read_line_stream();
		args = parse_string(line);
		report = execute(args);

		free(line);
		free(args);

		if (report >= 0)
		{
			exit(report);
		}
	}
		while (report == -1);
}
