#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "basic_shell.h"
#include <stddef.h>


struct builtins builtin_func_list[] = {
	{ "env", own_env },
	{ "help", own_help },
	{ "cd", own_cd },
	{ "exit", own_exit },

	{ NULL, NULL } /* last element must be NULL to signify end of list */
};

#endif
