#include "basic_shell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int next_process(char **args)
{
    pid_t pid;
    int report;

    struct stat st;
    if (stat(args[0], &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
    {
        pid = fork();
        if (pid == 0)
        {
            char *env[] = {"PATH=", "", NULL};
            if (execve(args[0], args, env) == -1)
            {
                perror("error in next_process");
            }
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            perror("forking: error in next_process");
        }
        else
        {
            do
            {
                waitpid(pid, &report, WUNTRACED);
            } while (!WIFEXITED(report) && !WIFSIGNALED(report));
        }
    }
    else
    {
        fprintf(stderr, "Error: %s is not a valid executable file.\n", args[0]);
    }

    return (-1);
}

