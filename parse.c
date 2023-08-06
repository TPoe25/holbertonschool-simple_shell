#include "basic_shell.h"

/**
 * parse_string - splits a string into multiple strings
 * @line: the input string to be divided
 * Return: a pointer to an array of strings (tokens)
 */
char **parse_string(char *line)
{
	int bufsize = 64;
	int s = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error in parse.\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
	{
		tokens[s] = token;
		s++;
		if (s >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "reallocation in parse.\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	tokens[s] = NULL;

	return (tokens);
}
