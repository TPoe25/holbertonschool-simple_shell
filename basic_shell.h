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
#include <sys/wait.h>

/* parse.c */
char **parse_string(char *line);

/* getlinefunc.c */
char *getlinefunc(void);

/* execute.c */
int execute(char **args);

/* next_process.c */
int next_process(char **args);

/* stream.c  */
char *read_line_stream(void);

/* automatedshell.c */
void automatedshell(void);

/* builtin functions */
int own_cd(char **args);
int own_exit(char **args);
int own_help(char **args);
int own_env(char **args);

#endif
