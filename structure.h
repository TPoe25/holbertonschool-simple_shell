#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "basic_shell.h"
#include <stddef.h>

/**
 * struct builtins - stored in system at start
 * @name: the name of the builtin function
 * @func: implements the builtin commands
 */
typedef struct builtins
{
	char *name; /*name of the builtin command */

	int (*func)(void); /*pointer to function*/
} builtins;

struct builtins builtin_commands[] = {
	{ "env", own_env },
	{ "help", own_help },
	{ "cd", own_cd },
	{ "exit", own_exit },

	{ NULL, NULL } /* last element must be NULL to signify end of list */
};	

#endif
