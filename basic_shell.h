#ifndef BASIC_SHELL_H
#define BASIC_SHELL_H

#define TOKEN_DELIM " \t\r\n\a"
extern char **environ;

#include "structure.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/* parse.c */
char **parse_string(char *line);

/* getlinefunc.c */
char *getlinefunc(void);

/* builtin functions */
int own_cd(char **args);
int own_exit(char **args);
int own_help(char **args);
int own_env(char **args);

#endif
