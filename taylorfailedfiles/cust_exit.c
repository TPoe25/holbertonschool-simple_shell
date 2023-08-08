#include "basic_shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * cust_exit - terminates the shell process
 * @args: arguments passed to the exit command (optional exit status)
 * Return: The exit status or -2 to indicate that the shell should not exit
 **/
int cust_exit(char **args)
{
    if (args[1])
    {
        int status = atoi(args[1]);
        if (status == 0 && strcmp(args[1], "0") != 0)
        {
            fprintf(stderr, "Exit: Invalid exit status\n");
            return (-2);
        }
        return (status);
    }
    else
    {
        return (-2);
    }
}
