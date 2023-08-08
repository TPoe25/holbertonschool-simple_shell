#include "basic_shell.h"

/**
 * input_shell - interactive mode for the shell
 **/

void input_shell(void)
{
	char *line;
	char **args;
	int report = -1;
	
	do {
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			printf("Basic $hell [%s]: ", cwd);
		} else {
			perror("getcwd");
			printf("Basic $hell: ");
		}
		line = read_line_stream(1);
		if (line == NULL)
		{
			break;
		}
		args = parse_string(line);
		report = execute(args);
		free(line);
		free(args);
	} while ((report != -2));
}