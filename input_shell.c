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
		printf("Basic_$hell: ");
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
