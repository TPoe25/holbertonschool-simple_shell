#ifndef BASIC_SHELL_H
#define BASIC_SHELL_H

#define TOKEN_DELIM " \t\r\n\a"
extern char **environ;

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/* parse.c */
char **parse_string(char *line);

/* getlinefunc.c */
char *getlinefunc(void);

#endif
