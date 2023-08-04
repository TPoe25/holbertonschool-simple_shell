#include "basic_shell.h"

/**
 * automatedshell - non interactive shell unix command line interepeter
 * @directories: an array of strings representing directories
 * Return: void
 **/

void automated_shell(char **directories, int interactive)
{
	char *line;
	char **args;
	int report = -1;

	do {
		line = read_line_stream(interactive);
		args = parse_string(line);
		
		if (!args[0])
			continue;

		report = execute(args, directories);

		free(line);
		free(args);

		if (report >= 0)
		{
			if (!interactive)
				break;
			exit(report);
		}
	}
		while (interactive);
}
