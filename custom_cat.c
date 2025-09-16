/* custom_cat.c
 * Simple cat command implementation:
 * - argc == 1 --> read from stdin
 * - argc >= 2 --> read contents of each file sequentially
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCK_SIZE 0x1000
char buf[BLOCK_SIZE];

// helper function to copy the contents of file descriptor to stdout
void content_fd_stdout(int fd) {
    while (1) {
        ssize_t bytes_read = read(fd, buf, BLOCK_SIZE);

        if (bytes_read == 0) break;           // EOF
        if (bytes_read < 0) { perror("read"); exit(EXIT_FAILURE); }

        ssize_t bytes_written = 0;
        while (bytes_written < bytes_read) {
            ssize_t w = write(STDOUT_FILENO, buf + bytes_written, bytes_read - bytes_written);
            if (w < 0) { perror("write"); exit(EXIT_FAILURE); }
            bytes_written += w;
        }
    }
}

int main(int argc, char *argv[]) {
    // No arguments: read from stdin (user)
    if (argc == 1) {
        content_fd_stdout(STDIN_FILENO);
    }

    // One or more files
    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd < 0) {
            perror(argv[i]);  // Show which file caused the error
            continue;         // Move on to the next file
        }
        content_fd_stdout(fd);
        close(fd);
    }

    return EXIT_SUCCESS;
}

   