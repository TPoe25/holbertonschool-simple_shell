#ifndef BASIC_SHELL_H
#define BASIC_SHELL_H
#define TOKEN_DELIM " \t\r\n\a"

#include "structure.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/* enviorment macro */
extern char **environ;

/* basic_shell.c */
int main(void);

/* input_shell */
void input_shell(void);

/* parse.c */
char **parse_string(char *line);

/* getlinefunc.c */
char *getlinefunc(void);

/* execute.c */
int execute(char **args);

/* next_process.c */
int next_process(char **args);

/* execute_process.c */
int execute_process(char *command, char **args);

/* stream.c  */
char *read_line_stream(int interactive);

/* automatedshell.c */
void automated_shell(void);

/* builtin functions */
int cust_cd(char **args);
int cust_exit(char **args);
int cust_env(char **args);

#endif
