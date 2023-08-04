#include "basic_shell.h"

/**
 * read_line_stream - reads a line from the stream
 * @interactive: flag telling whether the shell is running in interactive mode
 * Return: pointer that points to line read
 */
char *read_line_stream(int interactive)
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
			if (interactive)
			{
				putchar('\n');
			}
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (symbol == '\n')
		{
			line[stream] = '\0';
			return (line);
		}
		line[stream] = symbol;
		stream++;
		if (stream >= bufsize)
		{
			bufsize += 1024;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "error reallocating in read_line_stream");
				exit(EXIT_FAILURE); }
		}
	}
	return (line); }
