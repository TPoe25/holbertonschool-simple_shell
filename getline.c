#include "basic_shell.h"

/**
 * getlinefunc - gets line i/o and allocates memory for which stream.
 *
 * Return: Success if reaches EOF, Failure if it does not read EOF
 */

char *getlinefunc(void)
{
	char *line;
	size_t bufsize = 0;

	/* getting input and allocating space for each stream  */
	if (getline(&line, &bufsize, stdin)  == -1)
	{
	/*input is defined, frees line to avoid leak and system call success*/
		if (feof(stdin))
		{
			free(line);
			return NULL;
		} /* if input is not defined, frees line to avoid leak and call failure  */
		else
		{
		free(line);
		perror("getlinefunc");
		exit(EXIT_FAILURE);
		}
	}
	/* returns line */
	return (line);
}
