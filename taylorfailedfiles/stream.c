#include "basic_shell.h"
/**
 * read_line_stream - reads a line from the stream
 * @interactive: 1 if running in interactive mode, 0 otherwise
 * Return: pointer that points to line read or NULL on end of input
 */
char *read_line_stream(int interactive)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t chars_read;
	int c;
	size_t stream = 0;

	if (interactive)
	{
		chars_read = getline(&line, &bufsize, stdin);
		if (chars_read == -1 && feof(stdin))
		{
			free(line);
			return (NULL); /* End of input in interactive mode */ } }
	else
	{
		while ((c = getchar()) != EOF)
		{
			if (c == '\n')
			{
				line[stream++] = c;
				break; /* End of line in non-interactive mode */ }
			line = realloc(line, bufsize + 1);
			if (!line)
			{
				perror("allocation error in stream");
				exit(EXIT_FAILURE); }
			line[stream++] = c;
			bufsize++; }
		if (stream == 0 && c == EOF)
		{
			free(line);
			return (NULL); /* End of input in non-interactive mode */ }
		line = realloc(line, bufsize + 1);
		if (!line)
		{
			perror("allocation error in stream");
			exit(EXIT_FAILURE); }
		line[stream] = '\0'; }
	return (line);
}
