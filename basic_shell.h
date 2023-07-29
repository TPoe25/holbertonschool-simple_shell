#ifndef BASIC_SHELL_H
#define BASIC_SHELL_H

#define TOKEN_DELIM " \t\r\n\a"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

char **parse_string(char *line);
char *getlinefunc(void);

#endif
