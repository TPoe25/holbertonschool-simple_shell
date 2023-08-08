#ifndef BASIC_SHELL_H
#define BASIC_SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/* execute.c */
int execute(char **args);

/* input_shell.c */
void input_shell(void);

/* parse.c */
char **parse_string(char *line);

/* read_line_stream */
char *read_line_stream(int interactive);

/* next_process.c */
int next_process(char **args);

/* execute_process.c */
int execute_process(char *command, char **args, char **envList);

/* automatedshell.c */
void automated_shell(void);

/* Define macros and constants */
#define TOKEN_DELIM " \t\r\n\a"

/* Declare global variables */
extern char **environ;

/* builtin functions */
int cust_cd(char **args);
int cust_exit(char **args);
int cust_env(char ** args);

#endif /* BASIC_SHELL_H */
