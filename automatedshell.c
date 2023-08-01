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

	setenv("PATH", "/usr/bin:/bin", 1);

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
