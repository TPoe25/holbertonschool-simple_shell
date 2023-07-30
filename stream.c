#include "basic_shell.h"

/**
 * read_line_stream - reads a line from the stream
 * Return: pointer that points to line read
 */

char *read_line_stream(void)
{
	int bufsize = 1024;
	int stream = 0;
	char *line = malloc(sizeof(char) * bufsize);
	int symbol;

	if (line == NULL)
	{
		fprintf(stderr, "error allocating in read_line_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		symbol = getchar();
		if (symbol == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (symbol == '\n')
		{
			line[stream] = '\0';
			return (line);
		}
		else
		{
			line[stream] = symbol;
		}
		stream++;
		if (stream >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "error reallocating in read_line_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
