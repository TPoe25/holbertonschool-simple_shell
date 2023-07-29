#include "basic_shell.h"
/**
 *parse_string - splits a string into multiple strings
 *@line: the input string to be divided
 *Return: a pointer to an array of strings (tokens)
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
		exit(EXIT_FAILURE); /*exit the program if mem allocate fails*/
	}
	token = strtok(line, TOKEN_DELIM);
	while (token != NULL)
{
	if (token[0] == '#') /* Handle Comments */
	{
		break;
	}
	token[s] = token; /*store the token in the tokens array*/
	s++;
	if (s >= bufsize)
	{ /*reallocate memeory for tokens */
		bufsize += bufsize;
		tokens = realloc(tokens, bufsize * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "reallocation error in parse.\n");
		exit(EXIT_FAILURE); /* exit program if reallocation fails*/
	}
	}
	token = strtok(NULL, TOKEN_DELIM);
}
	tokens[s] = NULL; /*sets last element of the token arrayto NULL*/
	return (tokens); /* Return the array of tokens */
}
