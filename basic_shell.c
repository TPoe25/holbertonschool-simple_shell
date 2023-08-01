#include "basic_shell.h"

/*
 * main - main function
 *
 * Return: always 0 success
 */
int main(void)
{
    char *ls_l_command[] = {"ls", "-l", NULL};
    char *ls_command[] = {"ls", NULL};

    automatedshell(ls_command);

    automatedshell(ls_l_command);

    return (0);
}

