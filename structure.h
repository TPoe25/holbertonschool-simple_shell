#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "basic_shell.h"
#include <stddef.h>

/**
 * struct builtins - stored in system at start
 * @name: the name of the builtin function
 * @func: implements the builtin commands
 */
struct builtin_func_list
{
	char *name; /*name of the builtin command */

	int (*func)(void); /*pointer to function*/
} builtin_func_list;

#endif
