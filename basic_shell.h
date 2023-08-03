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
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)));

/* input_shell */
void input_shell(char **directories);

/* copy_file.c */
int copy_file(const char *source_path, const char *dest_path);

/* parse.c */
char **parse_string(char *line);

/* getlinefunc.c */
char *getlinefunc(void);

/* execute.c */
int execute(char **args, char **directories);

/* next_process.c */
int next_process(char **args, char **directories);

/* find_command.c */
char *find_command(const char *command, char **directories);

/* stream.c  */
char *read_line_stream(void);

/* automatedshell.c */
void automatedshell(char **directories);

/* cust_env.c */
int cust_env(char **args);

/* builtin functions */
int cust_cd(char **args);
int cust_exit(char **args);
int cust_env(char **args);

#endif
