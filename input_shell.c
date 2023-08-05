#include "basic_shell.h"

/**
 * input_shell - interactive mode
 * @directories: array of args
 **/

void input_shell(void)
{
	char *line;
	char **args;
	int report = -1;

	do {
		printf("Basic $hell: ");
		line = read_line_stream(1);
		if (line == NULL)
		{
			break;
		}

		args = parse_string(line);
		report = execute(args);

		free(line);
		free(args);

		if (report >= 0)
		{
			exit(report);
		}
	} while (report == -1);
}
