#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stddef.h>

/**
 * struct builtins - stored in system at start
 * @name: the name of the builtin function
 * @func: implements the builtin commands
 */
struct builtins
{
	char *name; /*name of the builtin command */
	int (*func)(char **); /*pointer to function*/
};

#endif
