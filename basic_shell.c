#include "basic_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    if (isatty(STDIN_FILENO) == 1)
    {
        input_shell();
    }
    else
    {
	char *args[] = {"/bin/ls", "-l", "/usr/", NULL};
        next_process(args);
    }
    return (0);
}

