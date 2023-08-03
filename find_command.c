#include "basic_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *find_command(const char *command, char **directories) {
    size_t i;
    
    /* Check if the command is an absolute or relative path */
    if (strchr(command, '/') != NULL) {
        /* Command is an absolute or relative path */
        if (access(command, X_OK) == 0) {
            return strdup(command);
        }
    } else {
        /* Command is not an absolute or relative path, search in directories */
        for (i = 0; directories[i] != NULL; i++) {
            size_t dir_len = strlen(directories[i]);
            size_t command_len = strlen(command);
            size_t full_path_len = dir_len + 1 + command_len + 1; /* +one for /'///'/ and +one for NULL */
            char *full_path = (char *)malloc(full_path_len);

            if (full_path == NULL) {
                perror("Memory allocation error in find_command");
                return NULL;
            }

            /* Construct the full path */
            strcpy(full_path, directories[i]);
            full_path[dir_len] = '/';
            strcpy(full_path + dir_len + 1, command);

            if (access(full_path, X_OK) == 0) {
                return full_path;
            }

            free(full_path);
        }
    }

    return NULL;
}

