#include "basic_shell.h"

/**
 * automated_shell - automated shell process that reads commands from a file
 * Return: void
 **/
void automated_shell(void)
{
	char cwd[1024];
	char *line;
	char **args;
	int report = -1;

	do {
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			fprintf(stdout,  "Basic $hell [%s]: ", cwd);
		} else
		{
			perror("getcwd");
			fprintf(stdout, "Basic $hell [%s]: ", cwd);
		}
		line = read_line_stream(0);
		if (line == NULL)
		{
			break;
		}
		args = parse_string(line);
		report = next_process(args);

		free(line);
		free(args);

		if (report >= 0)
		{
			exit(report);
		}
	} while (1);
}
