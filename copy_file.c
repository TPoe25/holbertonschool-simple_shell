#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int copy_file(const char *source_path, const char *dest_path) {
    int source_fd, dest_fd;
    ssize_t bytesRead, bytesWritten;
    char buffer[4096];

    source_fd = open(source_path, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return -1;
    }

    dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        return -1;
    }

    while ((bytesRead = read(source_fd, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(dest_fd, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return -1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
    }

    close(source_fd);
    close(dest_fd);
    return 0;
}
