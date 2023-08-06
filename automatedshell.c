#include "basic_shell.h"

/**
 * automated_shell - automated shell process that reads commands from a file
 * Return: void
 **/
void automated_shell(void)
{
	char *line;
	char **args;
	int report = -1;

	while ((line = read_line_stream(0)))
	{
		args = parse_string(line);
		report = execute(args);
		free(line);
		free(args);

		if (report >= 0)
		{
			exit(report);
		}
	}
}
